/**Файл запилен ради одной функции
 *
 *
 *
 *
 *
 *
 *
 */
#include "hw_cm_per.h"
#include  "soc_AM335x.h"
#include "syl_mmcsd_proto.h"
#include "hw_types.h"
#include "hw_intc.h"
#include "emmcFat.h"
#include "edma_event.h"
#include "edma.h"
#include "consoleUtils.h"
#include "hs_mmcsd.h"

/* SD Controller info structure */
extern mmcsdCtrlInfo  ctrlInfo;
//Обрубание клоков ДМА модуля
void EDMAModuleClkDisable(void)
{

    /* Configuring clocks for EDMA3 TPCC and TPTCs. */

    /* Writing to MODULEMODE field of CM_PER_TPCC_CLKCTRL register. */
    HWREG(SOC_CM_PER_REGS + CM_PER_TPCC_CLKCTRL) &=
    		~CM_PER_TPCC_CLKCTRL_MODULEMODE_ENABLE;

    /* Waiting for MODULEMODE field to reflect the written value. */
    while(CM_PER_TPCC_CLKCTRL_MODULEMODE_DISABLE !=
          (HWREG(SOC_CM_PER_REGS + CM_PER_TPCC_CLKCTRL) &
          CM_PER_TPCC_CLKCTRL_MODULEMODE));

    /* Writing to MODULEMODE field of CM_PER_TPTC0_CLKCTRL register. */
    HWREG(SOC_CM_PER_REGS + CM_PER_TPTC0_CLKCTRL) &=
    		~CM_PER_TPTC0_CLKCTRL_MODULEMODE_ENABLE;

    /* Waiting for MODULEMODE field to reflect the written value. */
    while(CM_PER_TPTC0_CLKCTRL_MODULEMODE_DISABLE !=
          (HWREG(SOC_CM_PER_REGS + CM_PER_TPTC0_CLKCTRL) &
           CM_PER_TPTC0_CLKCTRL_MODULEMODE));

    /* Writing to MODULEMODE field of CM_PER_TPTC1_CLKCTRL register. */
    HWREG(SOC_CM_PER_REGS + CM_PER_TPTC1_CLKCTRL) &=
    		~CM_PER_TPTC1_CLKCTRL_MODULEMODE_ENABLE;

    /* Waiting for MODULEMODE field to reflect the written value. */
    while(CM_PER_TPTC1_CLKCTRL_MODULEMODE_DISABLE !=
          (HWREG(SOC_CM_PER_REGS + CM_PER_TPTC1_CLKCTRL) &
           CM_PER_TPTC1_CLKCTRL_MODULEMODE));

    /* Writing to MODULEMODE field of CM_PER_TPTC2_CLKCTRL register. */
    HWREG(SOC_CM_PER_REGS + CM_PER_TPTC2_CLKCTRL) &=
    		~CM_PER_TPTC2_CLKCTRL_MODULEMODE_ENABLE;

    /* Waiting for MODULEMODE field to reflect the written value. */
    while(CM_PER_TPTC2_CLKCTRL_MODULEMODE_DISABLE !=
          (HWREG(SOC_CM_PER_REGS + CM_PER_TPTC2_CLKCTRL) &
           CM_PER_TPTC2_CLKCTRL_MODULEMODE));
}
/*******************************************************************************
**
** Здесь вырубаем контроллер прерываний, дма контроллер, контроллер еммс
**
*******************************************************************************/
void resetmodules(void)
{
	/*eMMC card and controller reset*/

    /* CMD0 - reset card */
    if(!MMCSDCardReset(&ctrlInfo))
    	ConsoleUtilsPrintf("\nFailed to reset eMMC card.\n");


    //softreset
    if (HSMMCSDSoftReset(ctrlInfo.memBase) != 0)
    {
    	ConsoleUtilsPrintf("HS MMC/SD Reset failed\n");
    }

    HWREG(0x48060000 + MMCHS_SYSCTL) =
            (HWREG(0x48060000 + MMCHS_SYSCTL) & ~MMCHS_SYSCTL_ICE) & ~MMCHS_SYSCTL_ICE;

    //eMMCSD clock disable
    HWREG(SOC_PRCM_REGS + CM_PER_MMC0_CLKCTRL) &=
    		CM_PER_MMC0_CLKCTRL_MODULEMODE_DISABLE;

    while((HWREG(SOC_PRCM_REGS + CM_PER_MMC0_CLKCTRL) &
      CM_PER_MMC0_CLKCTRL_MODULEMODE) != CM_PER_MMC0_CLKCTRL_MODULEMODE_DISABLE);

	//INTC reset
    /* Reset the ARM interrupt controller */
    HWREG(SOC_AINTC_REGS + INTC_SYSCONFIG) = INTC_SYSCONFIG_SOFTRESET;

    /* Wait for the reset to complete */
    while((HWREG(SOC_AINTC_REGS + INTC_SYSSTATUS) & INTC_SYSSTATUS_RESETDONE) != INTC_SYSSTATUS_RESETDONE);

    /*DMA channel unmap + clock gating*/
    EDMA3FreeChannel(EDMA_INST_BASE, 0,
                        MMCSD_TX_EDMA_CHAN, EDMA3_TRIG_MODE_EVENT,
						MMCSD_TX_EDMA_CHAN, EVT_QUEUE_NUM);
    EDMA3FreeChannel(EDMA_INST_BASE, 0,
                        MMCSD_RX_EDMA_CHAN, EDMA3_TRIG_MODE_EVENT,
						MMCSD_RX_EDMA_CHAN, EVT_QUEUE_NUM);
    //clock disable
    EDMAModuleClkDisable();

}

