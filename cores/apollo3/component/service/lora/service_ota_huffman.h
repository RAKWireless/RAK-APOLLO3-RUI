#ifndef __SERVICE_OTA_HUFFMAN_H
#define __SERVICE_OTA_HUFFMAN_H

#include <stdint.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "udrv_flash.h"
#include "udrv_serial.h"


typedef struct huffman_node_tag
{
	unsigned char isLeaf;
	unsigned long count;
	struct huffman_node_tag* parent;

	union
	{
		struct
		{
			struct huffman_node_tag *zero, *one;
		};
		unsigned char symbol;
	};
} huffman_node;

extern unsigned int number;




void free_huffman_tree(huffman_node* subtree);

huffman_node* read_code_table_from_memory(const unsigned char* haff_addr,
						               unsigned int haff_len,
						               uint32_t* pDataBytes,
									   unsigned int* pindex);
						 
			  
huffman_node* huffman_decode_memory(const unsigned char* data_addr,
			  uint32_t data_len,
			  unsigned char* pbufout,
			  uint32_t* pbufoutlen,
			  huffman_node* root,huffman_node* last_p,
			  uint32_t *pData_num);
#endif

