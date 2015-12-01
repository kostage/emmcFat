/****************************************************************************/
/*  AM335x.cmd                                                              */
/*  Copyright (c) 2014  Texas Instruments Incorporated                      */
/*  Author: Rafael de Souza                                                 */
/*                                                                          */
/*    Description: This file is a sample linker command file that can be    */
/*                 used for linking programs built with the C compiler and  */
/*                 running the resulting .out file on an AM335x device.     */
/*                 Use it as a guideline.  You will want to                 */
/*                 change the memory layout to match your specific          */
/*                 target system.  You may want to change the allocation    */
/*                 scheme according to the size of your program.            */
/*                                                                          */
/****************************************************************************/
//-stack  0x0008                             /* SOFTWARE STACK SIZE           */
//-heap   0x2000                             /* HEAP AREA SIZE                */
-e Entry
/* Since we used 'Entry' as the entry-point symbol the compiler issues a    */
/* warning (#10063-D: entry-point symbol other than "_c_int00" specified:   */
/* "Entry"). The CCS Version (5.1.0.08000) stops building from command      */
/* line when there is a warning. So this warning is suppressed with the     */
/* below flag. */

--diag_suppress=10063

/*0x402F0400*//*0x1FBFF*/
MEMORY
{
        IRAM_MEM : org = 0x402F0400  len = 0x1B400            //PUBLIC RAM 109KB
        DDR_MEM : org = 0x8F000000  len = 0x1B400            //PUBLIC RAM 109KB
        DDR_MEM_BSS        : org = 0x90000000  len = 0x7FFFFFF           /* RAM */
}

// SPECIFY THE SECTIONS ALLOCATION INTO MEMORY
SECTIONS
{
	.text:Entry : load > 0x402F0400
    .text    : load > DDR_MEM              // CODE
    .data    : load > DDR_MEM              // INITIALIZED GLOBAL AND STATIC VARIABLES.
    .bss     : load > DDR_MEM_BSS              // UNINITIALIZED OR ZERO INITIALIZED
                    RUN_START(bss_start)
                    RUN_END(bss_end)
    .sysmem  : load > DDR_MEM                                         // GLOBAL & STATIC VARIABLES.
    .const   : load > DDR_MEM              // GLOBAL CONSTANTS
    .stack   : load > DDR_MEM HIGH           // SOFTWARE SYSTEM STACK  загоняем стек в самы конец
}
