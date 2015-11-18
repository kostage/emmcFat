/*
 * emmcFat.h
 *
 *  Created on: 18 םמÿב. 2015 ד.
 *      Author: doroshenko_kp
 */

#ifndef EMMCFAT_H_
#define EMMCFAT_H_

/******************************************************************************
**                      INTERNAL MACRO DEFINITIONS
*******************************************************************************/
//#define SD

#ifndef SD
#define EMMC
#endif
/* Frequency */
#define HSMMCSD_IN_FREQ                96000000 /* 96MHz */
#define HSMMCSD_INIT_FREQ              400000   /* 400kHz */

#define HSMMCSD_CARD_DETECT_PINNUM     6

/* EDMA3 Event queue number. */
#define EVT_QUEUE_NUM                  0 //גלוסעמ 0

/* EDMA3 Region Number. */
#define REGION_NUMBER                  0

/* Block size config */
#define HSMMCSD_BLK_SIZE               512
#define HSMMCSD_RW_BLK                 1

/* Global data pointers */
#define HSMMCSD_DATA_SIZE              512

/* GPIO instance related macros. */
#define GPIO_INST_BASE                 (SOC_GPIO_0_REGS)

/* MMCSD instance related macros. */
#ifdef SD
#define MMCSD_INST_BASE                (SOC_MMCHS_0_REGS)
#define MMCSD_INT_NUM                  (SYS_INT_MMCSD0INT)
#endif
#ifdef EMMC
#define MMCSD_INST_BASE                (SOC_MMCHS_1_REGS)
#define MMCSD_INT_NUM                  (SYS_INT_MMCSD1INT)
#endif

/* EDMA instance related macros. */
#define EDMA_INST_BASE                 (SOC_EDMA30CC_0_REGS)
#define EDMA_COMPLTN_INT_NUM           (SYS_INT_EDMACOMPINT)
#define EDMA_ERROR_INT_NUM             (SYS_INT_EDMAERRINT)

/* EDMA Events */
#ifdef SD
#define MMCSD_TX_EDMA_CHAN             (EDMA3_CHA_MMCSD0_TX)
#define MMCSD_RX_EDMA_CHAN             (EDMA3_CHA_MMCSD0_RX)
#endif

#ifndef SD
#define MMCSD_TX_EDMA_CHAN             (EDMA3_CHA_MMCSD1_TX)
#define MMCSD_RX_EDMA_CHAN             (EDMA3_CHA_MMCSD1_RX)
#endif
/* MMU related macros. */
#define START_ADDR_OCMC                 0x40300000
#define START_ADDR_DDR                  0x80000000
#define START_ADDR_DEV                  0x44000000
#define NUM_SECTIONS_DDR                512
#define NUM_SECTIONS_DEV                960
#define NUM_SECTIONS_OCMC               1


/*****************************************************************************
**                INTERNAL MACRO DEFINITIONS GPIO3
*****************************************************************************/
#define GPIO_INSTANCE_ADDRESS           (SOC_GPIO_1_REGS)
#define GPIO_INSTANCE_PIN_NUMBER        (20)
#define GPIO2_INSTANCE_ADDRESS           (SOC_GPIO_2_REGS)


#endif /* EMMCFAT_H_ */
