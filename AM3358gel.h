/*
 * AM3358gel.h
 *
 *  Created on: 22 сент. 2015 г.
 *      Author: doroshenko_kp
 */

#ifndef AM3358GEL_H_
#define AM3358GEL_H_


//####################################################
//AM335x BeagleBlack GEL file (DDR3)
//v1.0 Jan8,2013 First revision, derived from EVM REV 1.3
//v1.1 Apr12,2013 Changed DDR settings for 400MHz DDR
//                Note: these changes are for production
//                version of BBB, which has 4Gb DDR.
//
//####################################################

//****************************************************
//PRCM module definitions
//****************************************************
#define PRCM_BASE_ADDR                    (0x44E00000)
#define CM_PER_EMIF_CLKCTRL               (PRCM_BASE_ADDR + 0x028)
#define CM_PER_EMIF_FW_CLKCTRL            (PRCM_BASE_ADDR + 0x0D0)

#define CM_AUTOIDLE_DPLL_MPU              (PRCM_BASE_ADDR + 0x41C)
#define CM_IDLEST_DPLL_MPU                (PRCM_BASE_ADDR + 0x420)
#define CM_CLKSEL_DPLL_MPU                (PRCM_BASE_ADDR + 0x42C)
#define CM_AUTOIDLE_DPLL_DDR              (PRCM_BASE_ADDR + 0x430)
#define CM_IDLEST_DPLL_DDR                (PRCM_BASE_ADDR + 0x434)
#define CM_CLKSEL_DPLL_DDR                (PRCM_BASE_ADDR + 0x440)
#define CM_AUTOIDLE_DPLL_DISP             (PRCM_BASE_ADDR + 0x444)
#define CM_IDLEST_DPLL_DISP               (PRCM_BASE_ADDR + 0x448)
#define CM_CLKSEL_DPLL_DISP               (PRCM_BASE_ADDR + 0x454)
#define CM_AUTOIDLE_DPLL_CORE             (PRCM_BASE_ADDR + 0x458)
#define CM_IDLEST_DPLL_CORE               (PRCM_BASE_ADDR + 0x45C)
#define CM_CLKSEL_DPLL_CORE               (PRCM_BASE_ADDR + 0x468)
#define CM_AUTOIDLE_DPLL_PER              (PRCM_BASE_ADDR + 0x46C)
#define CM_IDLEST_DPLL_PER                (PRCM_BASE_ADDR + 0x470)
#define CM_CLKSEL_DPLL_PER                (PRCM_BASE_ADDR + 0x49C)

#define CM_DIV_M4_DPLL_CORE               (PRCM_BASE_ADDR + 0x480)
#define CM_DIV_M5_DPLL_CORE               (PRCM_BASE_ADDR + 0x484)
#define CM_CLKMODE_DPLL_MPU               (PRCM_BASE_ADDR + 0x488)
#define CM_CLKMODE_DPLL_PER               (PRCM_BASE_ADDR + 0x48C)
#define CM_CLKMODE_DPLL_CORE              (PRCM_BASE_ADDR + 0x490)
#define CM_CLKMODE_DPLL_DDR               (PRCM_BASE_ADDR + 0x494)
#define CM_CLKMODE_DPLL_DISP              (PRCM_BASE_ADDR + 0x498)

#define CM_DIV_M2_DPLL_DDR                (PRCM_BASE_ADDR + 0x4A0)
#define CM_DIV_M2_DPLL_DISP               (PRCM_BASE_ADDR + 0x4A4)
#define CM_DIV_M2_DPLL_MPU                (PRCM_BASE_ADDR + 0x4A8)
#define CM_DIV_M2_DPLL_PER                (PRCM_BASE_ADDR + 0x4AC)
#define CM_DIV_M6_DPLL_CORE               (PRCM_BASE_ADDR + 0x4D8)

#define CM_CLKOUT_CTRL                    (PRCM_BASE_ADDR + 0x700)

//****************************************************
//Control module definitions
//****************************************************

#define CONTROL_BASE_ADDR       (0x44E10000)

#define CONTROL_STATUS          (CONTROL_BASE_ADDR + 0x40)
#define CONF_XDMA_EVENT_INTR1   (CONTROL_BASE_ADDR + 0x9b4)

//DDR IO Control Registers
#define DDR_IO_CTRL             (CONTROL_BASE_ADDR + 0x0E04)
#define VTP_CTRL_REG            (CONTROL_BASE_ADDR + 0x0E0C)
#define DDR_CKE_CTRL            (CONTROL_BASE_ADDR + 0x131C)
#define DDR_CMD0_IOCTRL         (CONTROL_BASE_ADDR + 0x1404)
#define DDR_CMD1_IOCTRL         (CONTROL_BASE_ADDR + 0x1408)
#define DDR_CMD2_IOCTRL         (CONTROL_BASE_ADDR + 0x140C)
#define DDR_DATA0_IOCTRL        (CONTROL_BASE_ADDR + 0x1440)
#define DDR_DATA1_IOCTRL        (CONTROL_BASE_ADDR + 0x1444)

//********************************************************************
//EMIF4DC module definitions
//********************************************************************
#define EMIF_BASE_ADDR                    (0x4C000000)
#define EMIF_STATUS_REG                   (EMIF_BASE_ADDR + 0x004)
#define EMIF_SDRAM_CONFIG_REG             (EMIF_BASE_ADDR + 0x008)
#define EMIF_SDRAM_CONFIG_2_REG           (EMIF_BASE_ADDR + 0x00C)
#define EMIF_SDRAM_REF_CTRL_REG           (EMIF_BASE_ADDR + 0x010)
#define EMIF_SDRAM_REF_CTRL_SHDW_REG      (EMIF_BASE_ADDR + 0x014)
#define EMIF_SDRAM_TIM_1_REG              (EMIF_BASE_ADDR + 0x018)
#define EMIF_SDRAM_TIM_1_SHDW_REG         (EMIF_BASE_ADDR + 0x01C)
#define EMIF_SDRAM_TIM_2_REG              (EMIF_BASE_ADDR + 0x020)
#define EMIF_SDRAM_TIM_2_SHDW_REG         (EMIF_BASE_ADDR + 0x024)
#define EMIF_SDRAM_TIM_3_REG              (EMIF_BASE_ADDR + 0x028)
#define EMIF_SDRAM_TIM_3_SHDW_REG         (EMIF_BASE_ADDR + 0x02C)
#define EMIF_LPDDR2_NVM_TIM_REG           (EMIF_BASE_ADDR + 0x030)
#define EMIF_LPDDR2_NVM_TIM_SHDW_REG      (EMIF_BASE_ADDR + 0x034)
#define EMIF_PWR_MGMT_CTRL_REG            (EMIF_BASE_ADDR + 0x038)
#define EMIF_PWR_MGMT_CTRL_SHDW_REG       (EMIF_BASE_ADDR + 0x03C)
#define EMIF_LPDDR2_MODE_REG_DATA_REG     (EMIF_BASE_ADDR + 0x040)
#define EMIF_LPDDR2_MODE_REG_CFG_REG      (EMIF_BASE_ADDR + 0x050)
#define EMIF_OCP_CONFIG_REG               (EMIF_BASE_ADDR + 0x054)
#define EMIF_OCP_CFG_VAL_1_REG            (EMIF_BASE_ADDR + 0x058)
#define EMIF_OCP_CFG_VAL_2_REG            (EMIF_BASE_ADDR + 0x05C)
#define EMIF_IODFT_TLGC_REG               (EMIF_BASE_ADDR + 0x060)
#define EMIF_IODFT_CTRL_MISR_RSLT_REG     (EMIF_BASE_ADDR + 0x064)
#define EMIF_IODFT_ADDR_MISR_RSLT_REG     (EMIF_BASE_ADDR + 0x068)
#define EMIF_IODFT_DATA_MISR_RSLT_1_REG   (EMIF_BASE_ADDR + 0x06C)
#define EMIF_IODFT_DATA_MISR_RSLT_2_REG   (EMIF_BASE_ADDR + 0x070)
#define EMIF_IODFT_DATA_MISR_RSLT_3_REG   (EMIF_BASE_ADDR + 0x074)
#define EMIF_PERF_CNT_1_REG               (EMIF_BASE_ADDR + 0x080)
#define EMIF_PERF_CNT_2_REG               (EMIF_BASE_ADDR + 0x084)
#define EMIF_PERF_CNT_CFG_REG             (EMIF_BASE_ADDR + 0x088)
#define EMIF_PERF_CNT_SEL_REG             (EMIF_BASE_ADDR + 0x08C)
#define EMIF_PERF_CNT_TIM_REG             (EMIF_BASE_ADDR + 0x090)
#define EMIF_READ_IDLE_CTRL_REG           (EMIF_BASE_ADDR + 0x098)
#define EMIF_READ_IDLE_CTRL_SHDW_REG      (EMIF_BASE_ADDR + 0x09C)
#define EMIF_IRQ_EOI_REG                  (EMIF_BASE_ADDR + 0x0A0)
#define EMIF_IRQSTATUS_RAW_SYS_REG        (EMIF_BASE_ADDR + 0x0A4)
#define EMIF_IRQSTATUS_SYS_REG            (EMIF_BASE_ADDR + 0x0AC)
#define EMIF_IRQENABLE_SET_SYS_REG        (EMIF_BASE_ADDR + 0x0B4)
#define EMIF_IRQENABLE_CLR_SYS_REG        (EMIF_BASE_ADDR + 0x0BC)
#define EMIF_ZQ_CONFIG_REG                (EMIF_BASE_ADDR + 0x0C8)
#define EMIF_TEMP_ALERT_CONFIG_REG        (EMIF_BASE_ADDR + 0x0CC)
#define EMIF_OCP_ERR_LOG_REG              (EMIF_BASE_ADDR + 0x0D0)
#define EMIF_RDWR_LVL_RMP_WIN_REG         (EMIF_BASE_ADDR + 0x0D4)
#define EMIF_RDWR_LVL_RMP_CTRL_REG        (EMIF_BASE_ADDR + 0x0D8)
#define EMIF_RDWR_LVL_CTRL_REG            (EMIF_BASE_ADDR + 0x0DC)
#define EMIF_DDR_PHY_CTRL_1_REG           (EMIF_BASE_ADDR + 0x0E4)
#define EMIF_DDR_PHY_CTRL_1_SHDW_REG      (EMIF_BASE_ADDR + 0x0E8)
#define EMIF_DDR_PHY_CTRL_2_REG           (EMIF_BASE_ADDR + 0x0EC)
#define EMIF_PRI_COS_MAP_REG              (EMIF_BASE_ADDR + 0x100)
#define EMIF_CONNID_COS_1_MAP_REG         (EMIF_BASE_ADDR + 0x104)
#define EMIF_CONNID_COS_2_MAP_REG         (EMIF_BASE_ADDR + 0x108)
#define EMIF_RD_WR_EXEC_THRSH_REG         (EMIF_BASE_ADDR + 0x120)


//*******************************************************************
//DDR PHY registers
//*******************************************************************
#define    DDR_PHY_BASE_ADDR                                   (0x44E12000)
//CMD0
#define    CMD0_REG_PHY_CTRL_SLAVE_RATIO_0                     (0x01C + DDR_PHY_BASE_ADDR)
#define    CMD0_REG_PHY_CTRL_SLAVE_FORCE_0                     (0x020 + DDR_PHY_BASE_ADDR)
#define    CMD0_REG_PHY_CTRL_SLAVE_DELAY_0                     (0x024 + DDR_PHY_BASE_ADDR)
#define    CMD0_REG_PHY_DLL_LOCK_DIFF_0                        (0x028 + DDR_PHY_BASE_ADDR)
#define    CMD0_REG_PHY_INVERT_CLKOUT_0                        (0x02C + DDR_PHY_BASE_ADDR)
#define    CMD0_PHY_REG_STATUS_PHY_CTRL_DLL_LOCK_0             (0x030 + DDR_PHY_BASE_ADDR)
#define    CMD0_PHY_REG_STATUS_PHY_CTRL_OF_IN_LOCK_STATE_0     (0x034 + DDR_PHY_BASE_ADDR)
#define    CMD0_PHY_REG_STATUS_PHY_CTRL_OF_IN_DELAY_VALUE_0    (0x038 + DDR_PHY_BASE_ADDR)
#define    CMD0_PHY_REG_STATUS_PHY_CTRL_OF_OUT_DELAY_VALUE_0   (0x03C + DDR_PHY_BASE_ADDR)

//CMD1
#define    CMD1_REG_PHY_CTRL_SLAVE_RATIO_0                     (0x050 + DDR_PHY_BASE_ADDR)
#define    CMD1_REG_PHY_CTRL_SLAVE_FORCE_0                     (0x054 + DDR_PHY_BASE_ADDR)
#define    CMD1_REG_PHY_CTRL_SLAVE_DELAY_0                     (0x058 + DDR_PHY_BASE_ADDR)
#define    CMD1_REG_PHY_DLL_LOCK_DIFF_0                        (0x05C + DDR_PHY_BASE_ADDR)
#define    CMD1_REG_PHY_INVERT_CLKOUT_0                        (0x060 + DDR_PHY_BASE_ADDR)
#define    CMD1_PHY_REG_STATUS_PHY_CTRL_DLL_LOCK_0             (0x064 + DDR_PHY_BASE_ADDR)
#define    CMD1_PHY_REG_STATUS_PHY_CTRL_OF_IN_LOCK_STATE_0     (0x068 + DDR_PHY_BASE_ADDR)
#define    CMD1_PHY_REG_STATUS_PHY_CTRL_OF_IN_DELAY_VALUE_0    (0x06C + DDR_PHY_BASE_ADDR)
#define    CMD1_PHY_REG_STATUS_PHY_CTRL_OF_OUT_DELAY_VALUE_0   (0x070 + DDR_PHY_BASE_ADDR)

//CMD2
#define    CMD2_REG_PHY_CTRL_SLAVE_RATIO_0                     (0x084 + DDR_PHY_BASE_ADDR)
#define    CMD2_REG_PHY_CTRL_SLAVE_FORCE_0                     (0x088 + DDR_PHY_BASE_ADDR)
#define    CMD2_REG_PHY_CTRL_SLAVE_DELAY_0                     (0x08C + DDR_PHY_BASE_ADDR)
#define    CMD2_REG_PHY_DLL_LOCK_DIFF_0                        (0x090 + DDR_PHY_BASE_ADDR)
#define    CMD2_REG_PHY_INVERT_CLKOUT_0                        (0x094 + DDR_PHY_BASE_ADDR)
#define    CMD2_PHY_REG_STATUS_PHY_CTRL_DLL_LOCK_0             (0x098 + DDR_PHY_BASE_ADDR)
#define    CMD2_PHY_REG_STATUS_PHY_CTRL_OF_IN_LOCK_STATE_0     (0x09C + DDR_PHY_BASE_ADDR)
#define    CMD2_PHY_REG_STATUS_PHY_CTRL_OF_IN_DELAY_VALUE_0    (0x0A0 + DDR_PHY_BASE_ADDR)
#define    CMD2_PHY_REG_STATUS_PHY_CTRL_OF_OUT_DELAY_VALUE_0   (0x0A4 + DDR_PHY_BASE_ADDR)

//DATA0
#define    DATA0_REG_PHY_DATA_SLICE_IN_USE_0                   (0x0B8 + DDR_PHY_BASE_ADDR)
#define    DATA0_REG_PHY_DIS_CALIB_RST_0                       (0x0BC + DDR_PHY_BASE_ADDR)
#define    DATA0_REG_PHY_RDC_FIFO_RST_ERR_CNT_CLR_0            (0x0C0 + DDR_PHY_BASE_ADDR)
#define    DATA0_PHY_RDC_FIFO_RST_ERR_CNT_0                    (0x0C4 + DDR_PHY_BASE_ADDR)
#define    DATA0_REG_PHY_RD_DQS_SLAVE_RATIO_0                  (0x0C8 + DDR_PHY_BASE_ADDR)
#define    DATA0_REG_PHY_RD_DQS_SLAVE_RATIO_1                  (0x0CC + DDR_PHY_BASE_ADDR)
#define    DATA0_REG_PHY_RD_DQS_SLAVE_FORCE_0                  (0x0D0 + DDR_PHY_BASE_ADDR)
#define    DATA0_REG_PHY_RD_DQS_SLAVE_DELAY_0                  (0x0D4 + DDR_PHY_BASE_ADDR)
#define    DATA0_REG_PHY_RD_DQS_SLAVE_DELAY_1                  (0x0D8 + DDR_PHY_BASE_ADDR)
#define    DATA0_REG_PHY_WR_DQS_SLAVE_RATIO_0                  (0x0DC + DDR_PHY_BASE_ADDR)
#define    DATA0_REG_PHY_WR_DQS_SLAVE_RATIO_1                  (0x0E0 + DDR_PHY_BASE_ADDR)
#define    DATA0_REG_PHY_WR_DQS_SLAVE_FORCE_0                  (0x0E4 + DDR_PHY_BASE_ADDR)
#define    DATA0_REG_PHY_WR_DQS_SLAVE_DELAY_0                  (0x0E8 + DDR_PHY_BASE_ADDR)
#define    DATA0_REG_PHY_WR_DQS_SLAVE_DELAY_1                  (0x0EC + DDR_PHY_BASE_ADDR)
#define    DATA0_REG_PHY_WRLVL_INIT_RATIO_0                    (0x0F0 + DDR_PHY_BASE_ADDR)
#define    DATA0_REG_PHY_WRLVL_INIT_RATIO_1                    (0x0F4 + DDR_PHY_BASE_ADDR)
#define    DATA0_REG_PHY_WRLVL_INIT_MODE_0                     (0x0F8 + DDR_PHY_BASE_ADDR)
#define    DATA0_REG_PHY_GATELVL_INIT_RATIO_0                  (0x0FC + DDR_PHY_BASE_ADDR)
#define    DATA0_REG_PHY_GATELVL_INIT_RATIO_1                  (0x100 + DDR_PHY_BASE_ADDR)
#define    DATA0_REG_PHY_GATELVL_INIT_MODE_0                   (0x104 + DDR_PHY_BASE_ADDR)
#define    DATA0_REG_PHY_FIFO_WE_SLAVE_RATIO_0                 (0x108 + DDR_PHY_BASE_ADDR)
#define    DATA0_REG_PHY_FIFO_WE_SLAVE_RATIO_1                 (0x10C + DDR_PHY_BASE_ADDR)
#define    DATA0_REG_PHY_FIFO_WE_IN_FORCE_0                    (0x110 + DDR_PHY_BASE_ADDR)
#define    DATA0_REG_PHY_FIFO_WE_IN_DELAY_0                    (0x114 + DDR_PHY_BASE_ADDR)
#define    DATA0_REG_PHY_FIFO_WE_IN_DELAY_1                    (0x118 + DDR_PHY_BASE_ADDR)
#define    DATA0_REG_PHY_DQ_OFFSET_0                           (0x11C + DDR_PHY_BASE_ADDR)
#define    DATA0_REG_PHY_WR_DATA_SLAVE_RATIO_0                 (0x120 + DDR_PHY_BASE_ADDR)
#define    DATA0_REG_PHY_WR_DATA_SLAVE_RATIO_1                 (0x124 + DDR_PHY_BASE_ADDR)
#define    DATA0_REG_PHY_WR_DATA_SLAVE_FORCE_0                 (0x128 + DDR_PHY_BASE_ADDR)
#define    DATA0_REG_PHY_WR_DATA_SLAVE_DELAY_0                 (0x12C + DDR_PHY_BASE_ADDR)
#define    DATA0_REG_PHY_WR_DATA_SLAVE_DELAY_1                 (0x130 + DDR_PHY_BASE_ADDR)
#define    DATA0_REG_PHY_USE_RANK0_DELAYS_0                    (0x134 + DDR_PHY_BASE_ADDR)
#define    DATA0_REG_PHY_DLL_LOCK_DIFF_0                       (0x138 + DDR_PHY_BASE_ADDR)
#define    DATA0_PHY_REG_STATUS_DLL_LOCK_0                     (0x13C + DDR_PHY_BASE_ADDR)
#define    DATA0_PHY_REG_STATUS_OF_IN_LOCK_STATE_0             (0x140 + DDR_PHY_BASE_ADDR)
#define    DATA0_PHY_REG_STATUS_OF_IN_DELAY_VALUE_0            (0x144 + DDR_PHY_BASE_ADDR)
#define    DATA0_PHY_REG_STATUS_OF_OUT_DELAY_VALUE_0           (0x148 + DDR_PHY_BASE_ADDR)

//DATA1
#define    DATA1_REG_PHY_DATA_SLICE_IN_USE_0                   (0x15C + DDR_PHY_BASE_ADDR)
#define    DATA1_REG_PHY_DIS_CALIB_RST_0                       (0x160 + DDR_PHY_BASE_ADDR)
#define    DATA1_REG_PHY_RDC_FIFO_RST_ERR_CNT_CLR_0            (0x164 + DDR_PHY_BASE_ADDR)
#define    DATA1_PHY_RDC_FIFO_RST_ERR_CNT_0                    (0x168 + DDR_PHY_BASE_ADDR)
#define    DATA1_REG_PHY_RD_DQS_SLAVE_RATIO_0                  (0x16C + DDR_PHY_BASE_ADDR)
#define    DATA1_REG_PHY_RD_DQS_SLAVE_RATIO_1                  (0x170 + DDR_PHY_BASE_ADDR)
#define    DATA1_REG_PHY_RD_DQS_SLAVE_FORCE_0                  (0x174 + DDR_PHY_BASE_ADDR)
#define    DATA1_REG_PHY_RD_DQS_SLAVE_DELAY_0                  (0x178 + DDR_PHY_BASE_ADDR)
#define    DATA1_REG_PHY_RD_DQS_SLAVE_DELAY_1                  (0x17C + DDR_PHY_BASE_ADDR)
#define    DATA1_REG_PHY_WR_DQS_SLAVE_RATIO_0                  (0x180 + DDR_PHY_BASE_ADDR)
#define    DATA1_REG_PHY_WR_DQS_SLAVE_RATIO_1                  (0x184 + DDR_PHY_BASE_ADDR)
#define    DATA1_REG_PHY_WR_DQS_SLAVE_FORCE_0                  (0x188 + DDR_PHY_BASE_ADDR)
#define    DATA1_REG_PHY_WR_DQS_SLAVE_DELAY_0                  (0x18C + DDR_PHY_BASE_ADDR)
#define    DATA1_REG_PHY_WR_DQS_SLAVE_DELAY_1                  (0x190 + DDR_PHY_BASE_ADDR)
#define    DATA1_REG_PHY_WRLVL_INIT_RATIO_0                    (0x194 + DDR_PHY_BASE_ADDR)
#define    DATA1_REG_PHY_WRLVL_INIT_RATIO_1                    (0x198 + DDR_PHY_BASE_ADDR)
#define    DATA1_REG_PHY_WRLVL_INIT_MODE_0                     (0x19C + DDR_PHY_BASE_ADDR)
#define    DATA1_REG_PHY_GATELVL_INIT_RATIO_0                  (0x1A0 + DDR_PHY_BASE_ADDR)
#define    DATA1_REG_PHY_GATELVL_INIT_RATIO_1                  (0x1A4 + DDR_PHY_BASE_ADDR)
#define    DATA1_REG_PHY_GATELVL_INIT_MODE_0                   (0x1A8 + DDR_PHY_BASE_ADDR)
#define    DATA1_REG_PHY_FIFO_WE_SLAVE_RATIO_0                 (0x1AC + DDR_PHY_BASE_ADDR)
#define    DATA1_REG_PHY_FIFO_WE_SLAVE_RATIO_1                 (0x1B0 + DDR_PHY_BASE_ADDR)
#define    DATA1_REG_PHY_FIFO_WE_IN_FORCE_0                    (0x1B4 + DDR_PHY_BASE_ADDR)
#define    DATA1_REG_PHY_FIFO_WE_IN_DELAY_0                    (0x1B8 + DDR_PHY_BASE_ADDR)
#define    DATA1_REG_PHY_FIFO_WE_IN_DELAY_1                    (0x1BC + DDR_PHY_BASE_ADDR)
#define    DATA1_REG_PHY_DQ_OFFSET_0                           (0x1C0 + DDR_PHY_BASE_ADDR)
#define    DATA1_REG_PHY_WR_DATA_SLAVE_RATIO_0                 (0x1C4 + DDR_PHY_BASE_ADDR)
#define    DATA1_REG_PHY_WR_DATA_SLAVE_RATIO_1                 (0x1C8 + DDR_PHY_BASE_ADDR)
#define    DATA1_REG_PHY_WR_DATA_SLAVE_FORCE_0                 (0x1CC + DDR_PHY_BASE_ADDR)
#define    DATA1_REG_PHY_WR_DATA_SLAVE_DELAY_0                 (0x1D0 + DDR_PHY_BASE_ADDR)
#define    DATA1_REG_PHY_WR_DATA_SLAVE_DELAY_1                 (0x1D4 + DDR_PHY_BASE_ADDR)
#define    DATA1_REG_PHY_USE_RANK0_DELAYS_0                    (0x1D8 + DDR_PHY_BASE_ADDR)
#define    DATA1_REG_PHY_DLL_LOCK_DIFF_0                       (0x1DC + DDR_PHY_BASE_ADDR)
#define    DATA1_PHY_REG_STATUS_DLL_LOCK_0                     (0x1E0 + DDR_PHY_BASE_ADDR)
#define    DATA1_PHY_REG_STATUS_OF_IN_LOCK_STATE_0             (0x1E4 + DDR_PHY_BASE_ADDR)
#define    DATA1_PHY_REG_STATUS_OF_IN_DELAY_VALUE_0            (0x1E8 + DDR_PHY_BASE_ADDR)
#define    DATA1_PHY_REG_STATUS_OF_OUT_DELAY_VALUE_0           (0x1EC + DDR_PHY_BASE_ADDR)

//FIFO
#define FIFO_WE_OUT0_IO_CONFIG_I_0                             (0x338 + DDR_PHY_BASE_ADDR)
#define FIFO_WE_OUT0_IO_CONFIG_SR_0                            (0x33C + DDR_PHY_BASE_ADDR)
#define FIFO_WE_OUT1_IO_CONFIG_I_0                             (0x340 + DDR_PHY_BASE_ADDR)
#define FIFO_WE_OUT1_IO_CONFIG_SR_0                            (0x344 + DDR_PHY_BASE_ADDR)
#define FIFO_WE_IN2_IO_CONFIG_I_0                              (0x348 + DDR_PHY_BASE_ADDR)
#define FIFO_WE_IN2_IO_CONFIG_SR_0                             (0x34C + DDR_PHY_BASE_ADDR)
#define FIFO_WE_IN3_IO_CONFIG_I_0                              (0x350 + DDR_PHY_BASE_ADDR)
#define FIFO_WE_IN3_IO_CONFIG_SR_0                             (0x354 + DDR_PHY_BASE_ADDR)

//Leveling
#define DATA0_REG_PHY_WRLVL_NUM_OF_DQ0                         (0x35C + DDR_PHY_BASE_ADDR)
#define DATA0_REG_PHY_GATELVL_NUM_OF_DQ0                       (0x360 + DDR_PHY_BASE_ADDR)
#define DATA1_REG_PHY_WRLVL_NUM_OF_DQ0                         (0x364 + DDR_PHY_BASE_ADDR)
#define DATA1_REG_PHY_GATELVL_NUM_OF_DQ0                       (0x368 + DDR_PHY_BASE_ADDR)

//*******************************************************************
//Watchdog Timer registers
//*******************************************************************
#define    WDT1_BASE_ADDR                                        (0x44E35000)
#define    WDT1_WSPR                                             (WDT1_BASE_ADDR + 0x48)

//*****************************************************************************
//Read write prototype
//*****************************************************************************
#define WR_MEM_32(addr, data) *(unsigned int*)(addr) = (unsigned int)(data)
#define RD_MEM_32(addr)       *(unsigned int*)(addr)
#define UWORD32               unsigned int

//*******************************************************************
//DDR3 PHY parameters
//*******************************************************************
#define  CMD_PHY_CTRL_SLAVE_RATIO       0x80
#define  CMD_PHY_INVERT_CLKOUT          0x0

#define  DATA_PHY_RD_DQS_SLAVE_RATIO    0x38
#define  DATA_PHY_FIFO_WE_SLAVE_RATIO   0x94 //RD DQS GATE
#define  DATA_PHY_WR_DQS_SLAVE_RATIO    0x44
#define  DATA_PHY_WR_DATA_SLAVE_RATIO   0x7d  //WRITE DATA

#define  DDR_IOCTRL_VALUE               (0x18B)


//******************************************************************
//EMIF parameters
//******************************************************************
// DDR3 = 400MHz

#define ALLOPP_DDR3_READ_LATENCY    0x07        //RD_Latency = (CL + 2) - 1; CL=6 for DDR3-1600 speed grade and CK of 2.5ns

//400MHz settings
#define ALLOPP_DDR3_SDRAM_TIMING1   0x0AAAD4DB
#define ALLOPP_DDR3_SDRAM_TIMING2   0x266B7FDA
#define ALLOPP_DDR3_SDRAM_TIMING3   0x501F867F

#define ALLOPP_DDR3_SDRAM_CONFIG    0x61C05332  //termination = 1 (RZQ/4)
                                                //dynamic ODT = 2 (RZQ/2)
                                                //SDRAM drive = 0 (RZQ/6)
                                                //CWL = 0 (CAS write latency = 5)
                                                //CL = 4 (CAS latency = 6)
                                                //ROWSIZE = 6 (15 row bits)
                                                //PAGESIZE = 2 (10 column bits)
#define ALLOPP_DDR3_REF_CTRL        0x00000C30  //400 * 7.8us = 0xC30
#define ALLOPP_DDR3_ZQ_CONFIG       0x50074BE4


#define NO_LOOP_CNT       250
#define DDR_START_ADDR    0x80000000


#define TPCC_BASE_ADDR          0x49000000
#define INT_SRAM_BASE_ADDR      0x00300000
#define DDR_BASE_ADDR           0x80000000
#define DMA_SIZE                512 /*Words*/
#define L3_OFFSET_ADDR          0x40000000
#define CPU_OFFSET_ADDR         0x40000000

#define CM_PER_TPTC0_CLKCTRL (PRCM_BASE_ADDR +0x0024)
#define CM_PER_TPCC_CLKCTRL  (PRCM_BASE_ADDR +0x00BC)
#define CM_PER_TPTC1_CLKCTRL (PRCM_BASE_ADDR +0x00FC)
#define CM_PER_TPTC2_CLKCTRL (PRCM_BASE_ADDR +0x0100)

void Disable_Watchdog();

//Set the processor to ARM mode and Supervisor mode after a file is loaded, on a
//restart or on a reset
//This will facilitate code loading and debug by putting the processor in a known
//state

//******************************************************************************
//Functions
//******************************************************************************

void AM335xStartState();
void OnFileLoaded();
void OnRestart();
void OnReset();
void InitCLK_DDR();
//******************************************************************************
//System Initialization
//******************************************************************************
void AM335x_BeagleBlack_Initialization();
void GetInputClockFrequency();
void ARM_Turbo_Config();
void ARM_OPP120_Config();
void ARM_OPP100_Config();
//**********************************************************************
//PLL Configuration functions
//**********************************************************************
void MPU_PLL_Config(UWORD32 CLKIN,UWORD32 N,UWORD32 M,UWORD32 M2);
void CORE_PLL_Config(UWORD32 CLKIN,UWORD32 N,UWORD32 M,UWORD32 M4,UWORD32 M5,UWORD32 M6);
void DDR_PLL_Config(UWORD32 CLKIN,UWORD32 N,UWORD32 M,UWORD32 M2);
void PER_PLL_Config(UWORD32 CLKIN,UWORD32 N,UWORD32 M,UWORD32 M2);
void DISP_PLL_Config(UWORD32 CLKIN,UWORD32 N,UWORD32 M,UWORD32 M2);
void Bypass_DISP_PLL();
//##############################################################################
//##############################################################################
//                       DDR Configuration Section
//##############################################################################
//##############################################################################

//******************************************************************
//DDR3=400MHz
//OPP100
//******************************************************************
void DDR3_EMIF_Config();
void PHY_Config_CMD();
void PHY_Config_DATA();
void EMIF_PRCM_CLK_ENABLE();
//************************************************************************
//VTP_Enable() routine                                                   *
//************************************************************************

void VTP_Enable();
#endif /* AM3358GEL_H_ */
