#include "service_ota_huffman.h"

#define BigLittleSwap32(A)  ((((uint32_t)(A) & 0xff000000) >> 24) | (((uint32_t)(A) & 0x00ff0000) >> 8) | (((uint32_t)(A) & 0x0000ff00) << 8) | (((uint32_t)(A) & 0x000000ff) << 24))

unsigned int number = 0;



int checkCPUendian()
{
       union{
              unsigned long int i;
              unsigned char s[4];
       }c;
       c.i = 0x12345678;
       return (0x12 == c.s[0]);

}



unsigned long int t_ntohl(unsigned long int n)
{
       // 若本机为大端，与网络字节序同，直接返回
       // 若本机为小端，网络数据转换成小端再返回
       return checkCPUendian() ? n : BigLittleSwap32(n);
}


void free_huffman_tree(huffman_node* subtree)
{
	if (subtree == NULL)
		return;

	if (!subtree->isLeaf)
	{
		free_huffman_tree(subtree->zero);
		free_huffman_tree(subtree->one);
	}

	free(subtree);
}



static unsigned long numbytes_from_numbits(unsigned long numbits)
{
	return numbits / 8 + (numbits % 8 ? 1 : 0);
}

/*
 * get_bit returns the ith bit in the bits array
 * in the 0th position of the return value.
 */
static unsigned char get_bit(unsigned char* bits, unsigned long i)
{
	return (bits[i / 8] >> i % 8) & 1;
}



static huffman_node* new_leaf_node(unsigned char symbol)
{
	//huffman_node p;
	huffman_node* p = (huffman_node*)malloc(sizeof(huffman_node));
	p->isLeaf = 1;
	p->symbol = symbol;
	p->count = 0;
	p->parent = 0;
	return p;
}

static huffman_node* new_nonleaf_node(unsigned long count, huffman_node* zero, huffman_node* one)
{
	huffman_node* p = (huffman_node*)malloc(sizeof(huffman_node));
	p->isLeaf = 0;
	p->count = count;
	p->zero = zero;
	p->one = one;
	p->parent = 0;

	return p;
}

 
static int memread(const unsigned char* buf,
		   unsigned int buflen,
		   unsigned int* pindex,
		   void* bufout,
		   unsigned int readlen)
{
	assert(buf && pindex && bufout);
	assert(buflen >= *pindex);
	if (buflen < *pindex)
		return 1;
	if (readlen + *pindex > buflen)
		return 1;
	memcpy(bufout, buf + *pindex, readlen);	
	*pindex += readlen;
	return 0;
}

huffman_node* read_code_table_from_memory(const unsigned char* haff_addr,
						 unsigned int haff_len,
						 uint32_t* pDataBytes,
						 unsigned int* pindex)
{
	huffman_node* root = new_nonleaf_node(0, NULL, NULL);
	uint32_t count;
	
	/* Read the number of entries.
	   (it is stored in network byte order). */
	if ( memread(haff_addr, haff_len, pindex, &count, sizeof(count)))
	{
		free_huffman_tree(root);
		return NULL;
	}
	count = t_ntohl(count);
	//udrv_serial_log_printf("Count: %4x\r\n",count);
	/* Read the number of data bytes this encoding represents. */
	if (memread(haff_addr, haff_len, pindex, pDataBytes, sizeof(*pDataBytes)))
	{
		free_huffman_tree(root);
		return NULL;
	}
	
	*pDataBytes = t_ntohl(*pDataBytes);
    //udrv_serial_log_printf("pDataBytes: %4x!\r\n",*pDataBytes);
	
	/* Read the entries. */
	//udrv_serial_log_printf("Read the entries\r\n");
	while (count-- > 0)
	{
		unsigned int curbit;
		unsigned char symbol;
		unsigned char numbits;
		unsigned char numbytes;
		unsigned char* bytes;
		huffman_node* p = root;

		if (memread(haff_addr, haff_len, pindex, &symbol, sizeof(symbol)))
		{
			free_huffman_tree(root);
			return NULL;
		}
        //udrv_serial_log_printf("symbol :%x\r\n",symbol);
		if (memread(haff_addr, haff_len, pindex, &numbits, sizeof(numbits)))
		{
			free_huffman_tree(root);
			return NULL;
		}
        //udrv_serial_log_printf("numbits :%x\r\n",numbits);
		
		
		
		numbytes = (unsigned char)numbytes_from_numbits(numbits);
		
		//udrv_serial_log_printf("numbytes :%x\r\n",numbytes);
		bytes = (unsigned char*)malloc(numbytes);
		
		
		if (memread(haff_addr, haff_len, pindex, bytes, numbytes))
		{
			//udrv_serial_log_printf("================\r\n");
			free(bytes);
			free_huffman_tree(root);
			return NULL;
		}
        
 
		/*
		 * Add the entry to the Huffman tree. The value
		 * of the current bit is used switch between
		 * zero and one child nodes in the tree. New nodes
		 * are added as needed in the tree.
		 */
 
		for (curbit = 0; curbit < numbits; ++curbit)
		{
			if (get_bit(bytes, curbit))
			{
				if (p->one == NULL)
				{
					p->one = curbit == (unsigned char)(numbits - 1)
						     ? new_leaf_node(symbol)
						     : new_nonleaf_node(0, NULL, NULL);
					p->one->parent = p;
				}
				p = p->one;
			}
			else
			{
				if (p->zero == NULL)
				{
					p->zero = curbit == (unsigned char)(numbits - 1)
						      ? new_leaf_node(symbol)
						      : new_nonleaf_node(0, NULL, NULL);
					p->zero->parent = p;
				}
				p = p->zero;
			}
		}
		free(bytes);
	}

	return root;
}


 
			  
huffman_node* huffman_decode_memory(const unsigned char* data_addr,
			  uint32_t data_len,
			  unsigned char* pbufout,
			  uint32_t* pbufoutlen,
			  huffman_node* root,
			  huffman_node* last_p,
			  uint32_t *pData_num)
{
	huffman_node *p;
	unsigned int data_count;
	unsigned int i = 0;
	unsigned int bufcur = 0;
    static unsigned int num = 0;

	
	/* Ensure the arguments are valid. */
	if (!pbufout || !pbufoutlen)
		return NULL;
	/* Read the Huffman code table. */
	//root = read_code_table_from_memory(data_addr, data_len, &data_count);
	if (!root)
		return NULL;
	/* Decode the memory.*/
	//udrv_serial_log_printf("start extracting data\r\n");
	number++; 
	if(number == 1) 
	{
		p = root;
	}
	else 
	{
		p = last_p;
	} 
	for (i = 0; i < data_len && (*pData_num > 0); i++)
	{				
		unsigned char byte = data_addr[i];   
		unsigned char mask = 1;
		while ( (*pData_num > 0)  &&  mask)
		{ 	
			p = byte & mask ? p->one : p->zero;
			mask <<= 1;
			if (p->isLeaf)
			{
				pbufout[bufcur++] = p->symbol;
				p = root;
				*pData_num = *pData_num  - 1;
			}
		}
	}
	*pbufoutlen = bufcur;
	return p;
	
}

