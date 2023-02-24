
/******************************************************************************
 *
 * flash.ld - Linker script for applications using startup_gcc.c
 *
 *****************************************************************************/
ENTRY(Reset_Handler)
BOOT_VERSION = 0x000FC000;

MEMORY
{
    ROMEM (rx) : ORIGIN = 0x00014000, LENGTH = 976K
    RWMEM (rwx) : ORIGIN = 0x10000000, LENGTH = 384K
}

SECTIONS
{
    .text :
    {
        . = ALIGN(4);
        KEEP(*(.isr_vector))
        KEEP(*(.patch))
        *(.text)
        *(.text*)

        . = ALIGN(4);  
        __init_array_start = .;
        KEEP(*(.init_array))        /* C++ constructors */ 
        KEEP(*(.ctors))             /* and vtable init */
        __init_array_end = .; 

        *(.rodata)
        *(.rodata*)
        . = ALIGN(4);
        _etext = .;
    } > ROMEM

    /* User stack section initialized by startup code. */
    .stack (NOLOAD):
    {
        . = ALIGN(8);
        *(.stack)
        *(.stack*)
        . = ALIGN(8);
    } > RWMEM

    .atcmd_queue :
    {
        PROVIDE(__start_atcmd_queue = .);
        KEEP(*(.atcmd_queue))
        PROVIDE(__stop_atcmd_queue = .);
    } > ROMEM

    .data :
    {
        . = ALIGN(4);
        _sdata = .;
        *(.data)
        *(.data*)
        . = ALIGN(4);
        _edata = .;
    } > RWMEM AT>ROMEM

    /* used by startup to initialize data */
    _init_data = LOADADDR(.data);

    .bss :
    {
        . = ALIGN(4);
        _sbss = .;
        *(.bss)
        *(.bss*)
        *(COMMON)
        . = ALIGN(4);
        _ebss = .;
    } > RWMEM

    .heap (COPY):
	{
		__end__ = .;
		PROVIDE(end = .);
		*(.heap*)
		__HeapLimit = .;
	} > RWMEM

    .ARM.extab   : { *(.ARM.extab* .gnu.linkonce.armextab.*) } > RWMEM
    .ARM : {
        __exidx_start = .;
        *(.ARM.exidx*)
        __exidx_end = .;
    } > RWMEM    

    /* remove the debugging information from the standard libraries */
    /DISCARD/ :
    {
     libc.a ( * )
     libm.a ( * )
     libgcc.a ( * )
    }

    .ARM.attributes 0 : { *(.ARM.attributes) }
}