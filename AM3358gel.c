/*
 * AM3358gel.c
 *
 *  Created on: 22 сент. 2015 г.
 *      Author: doroshenko_kp
 */

//*****************************************************************************
//Базовая инициализация цельнотянутая из ti gel файла - PROFIT!
//*****************************************************************************
#include "AM3358gel.h"


//*****************************************************************************
//Global variables
//*****************************************************************************
UWORD32 CLKIN = 24;


//*****************************************************************************
//Global Functions
//*****************************************************************************

//Watchdog is disabled to eliminate warm resets during debug
void Disable_Watchdog()
{
    WR_MEM_32(WDT1_WSPR,0x0000AAAA);
    WR_MEM_32(WDT1_WSPR,0x00005555);
}

//Set the processor to ARM mode and Supervisor mode after a file is loaded, on a
//restart or on a reset
//This will facilitate code loading and debug by putting the processor in a known
//state


void AM335xStartState()
{
//	CPSR &= ~0x20;
//	CPSR = (CPSR & ~0x1F) | 0x13;
////	CPSR =	0x0;
//	unsigned int tmp = _get_CPSR();
//	tmp &= ~0x20;
//	_set_CPSR(tmp);

	unsigned int tmp = _get_CPSR();
	tmp = (tmp & ~0x1F) | 0x13;
	_set_CPSR(tmp);
}

void OnFileLoaded()
{
   AM335xStartState();
}

void OnRestart()
{
   AM335xStartState();
}

void OnReset()
{
   AM335xStartState();
   Disable_Watchdog();
}

void InitCLK_DDR()
{
	GetInputClockFrequency();
    AM335x_BeagleBlack_Initialization();
    Disable_Watchdog();
}

//******************************************************************************
//System Initialization
//******************************************************************************
void AM335x_BeagleBlack_Initialization()
    {
    //ARM_OPP100_Config();
	ARM_OPP100_Config();
    DDR3_EMIF_Config();
    }

void GetInputClockFrequency()
{
    UWORD32 temp;

    temp = RD_MEM_32(CONTROL_STATUS) >> 22;
    temp = temp & 0x3;
    if (temp == 0)
    {
        CLKIN = 19;  //19.2MHz
//        GEL_TextOut("Input Clock Read from SYSBOOT[15:14]:  19.2MHz\n","Output",1,1,1);
    }
    if (temp == 1)
    {
        CLKIN = 24;  //24MHz
//        GEL_TextOut("Input Clock Read from SYSBOOT[15:14]:  24MHz\n","Output",1,1,1);
    }
    if (temp == 2)
    {
        CLKIN = 25;  //25MHz
//        GEL_TextOut("Input Clock Read from SYSBOOT[15:14]:  25MHz\n","Output",1,1,1);
    }
    if (temp == 3)
    {
        CLKIN = 26;  //26MHz
//        GEL_TextOut("Input Clock Read from SYSBOOT[15:14]:  26MHz\n","Output",1,1,1);
    }
}

void ARM_Turbo_Config()
{
//	unsigned int i;
//	for(i=0;i<100000;i++);

	MPU_PLL_Config(  CLKIN, 23, 720, 1);
	CORE_PLL_Config( CLKIN, 23, 1000, 10, 8, 4);
	DDR_PLL_Config(  CLKIN, 23, 400, 1);
	PER_PLL_Config(  CLKIN, 23, 960, 5);
	DISP_PLL_Config( CLKIN, 23, 48, 1);
}

void ARM_OPP120_Config()
{
//	unsigned int i;
//	for(i=0;i<100000;i++);

	MPU_PLL_Config(  CLKIN, 23, 600, 1);
	CORE_PLL_Config( CLKIN, 23, 1000, 10, 8, 4);
	DDR_PLL_Config(  CLKIN, 23, 400, 1);
	PER_PLL_Config(  CLKIN, 23, 960, 5);
	DISP_PLL_Config( CLKIN, 23, 48, 1);
}

void ARM_OPP100_Config()
{
   //MPU_PLL_Config(  CLKIN, 23, 500, 1);
   MPU_PLL_Config(  CLKIN, 23, 600, 1);
//	MPU_PLL_Config(  CLKIN, 23, 300, 1);
   CORE_PLL_Config( CLKIN, 23, 1000, 10, 8, 4);
   DDR_PLL_Config(  CLKIN, 23, 400, 1);
   PER_PLL_Config(  CLKIN, 23, 960, 5);
   DISP_PLL_Config( CLKIN, 23, 48, 1);
}

//**********************************************************************
//PLL Configuration functions
//**********************************************************************
void MPU_PLL_Config(UWORD32 CLKIN,UWORD32 N,UWORD32 M,UWORD32 M2)
{
	UWORD32 clkmode,clksel,div_m2;


	clkmode=RD_MEM_32(CM_CLKMODE_DPLL_MPU);
	clksel= RD_MEM_32(CM_CLKSEL_DPLL_MPU);
	div_m2= RD_MEM_32(CM_DIV_M2_DPLL_MPU);


	//put the DPLL in bypass mode
	WR_MEM_32(CM_CLKMODE_DPLL_MPU,0x4);

	while(((RD_MEM_32(CM_IDLEST_DPLL_MPU) & 0x101) != 0x00000100)); //wait for bypass status


	//set multiply and divide values
	clksel = clksel & (~0x7FFFF);
	clksel = clksel | ((M <<0x8) | N);
	WR_MEM_32(CM_CLKSEL_DPLL_MPU,clksel);
	div_m2 = div_m2 & ~0x1F;
	div_m2 = div_m2 | M2;
	WR_MEM_32(CM_DIV_M2_DPLL_MPU,div_m2);

	//now lock the DPLL
	clkmode = clkmode | 0x7;  //enables lock mode
	WR_MEM_32(CM_CLKMODE_DPLL_MPU,clkmode);
	while(((RD_MEM_32(CM_IDLEST_DPLL_MPU) & 0x101) != 0x1)); //wait for lock
}

void CORE_PLL_Config(UWORD32 CLKIN,UWORD32 N,UWORD32 M,UWORD32 M4,UWORD32 M5,UWORD32 M6)
{
	UWORD32 clkmode,clksel,div_m4,div_m5,div_m6;


	clkmode=RD_MEM_32(CM_CLKMODE_DPLL_CORE);
	clksel= RD_MEM_32(CM_CLKSEL_DPLL_CORE);
	div_m4= RD_MEM_32(CM_DIV_M4_DPLL_CORE);
	div_m5= RD_MEM_32(CM_DIV_M5_DPLL_CORE);
	div_m6= RD_MEM_32(CM_DIV_M6_DPLL_CORE);

	//put DPLL in bypass mode
	clkmode = (clkmode & 0xfffffff8)|0x00000004;
	WR_MEM_32(CM_CLKMODE_DPLL_CORE,clkmode);
	while((RD_MEM_32(CM_IDLEST_DPLL_CORE) & 0x00000100 )!=0x00000100); //wait for bypass status

	//set multiply and divide values
	clksel = clksel & (~0x7FFFF);
	clksel = clksel | ((M <<0x8) | N);
	WR_MEM_32(CM_CLKSEL_DPLL_CORE,clksel);
	div_m4= M4;   //200MHz
	WR_MEM_32(CM_DIV_M4_DPLL_CORE,div_m4);
	div_m5=  M5;  //250MHz
	WR_MEM_32(CM_DIV_M5_DPLL_CORE,div_m5);
	div_m6=  M6;  //500MHz
	WR_MEM_32(CM_DIV_M6_DPLL_CORE,div_m6);

	//now lock the PLL
	clkmode =(clkmode&0xfffffff8)|0x00000007;
	WR_MEM_32(CM_CLKMODE_DPLL_CORE,clkmode);

	while((RD_MEM_32(CM_IDLEST_DPLL_CORE) & 0x00000001 )!=0x00000001);
}

void DDR_PLL_Config(UWORD32 CLKIN,UWORD32 N,UWORD32 M,UWORD32 M2)
{
	UWORD32 clkmode,clksel,div_m2;


	clkmode=RD_MEM_32(CM_CLKMODE_DPLL_DDR);
	clksel= RD_MEM_32(CM_CLKSEL_DPLL_DDR);
	div_m2= RD_MEM_32(CM_DIV_M2_DPLL_DDR);

	clkmode =(clkmode&0xfffffff8)|0x00000004;
	WR_MEM_32(CM_CLKMODE_DPLL_DDR,clkmode);
	while((RD_MEM_32(CM_IDLEST_DPLL_DDR) & 0x00000100 )!=0x00000100);

	clksel = clksel & (~0x7FFFF);
	clksel = clksel | ((M <<0x8) | N);
	WR_MEM_32(CM_CLKSEL_DPLL_DDR,clksel);
	div_m2 = RD_MEM_32(CM_DIV_M2_DPLL_DDR);
	div_m2 = (div_m2&0xFFFFFFE0) | M2;
	WR_MEM_32(CM_DIV_M2_DPLL_DDR,div_m2);
	clkmode =(clkmode&0xfffffff8)|0x00000007;
	WR_MEM_32(CM_CLKMODE_DPLL_DDR,clkmode);


	while((RD_MEM_32(CM_IDLEST_DPLL_DDR) & 0x00000001 )!=0x00000001);

}

void PER_PLL_Config(UWORD32 CLKIN,UWORD32 N,UWORD32 M,UWORD32 M2)
{
	UWORD32 clkmode,clksel,div_m2;


	clkmode=RD_MEM_32(CM_CLKMODE_DPLL_PER);
	clksel= RD_MEM_32(CM_CLKSEL_DPLL_PER);
	div_m2= RD_MEM_32(CM_DIV_M2_DPLL_PER);

	clkmode =(clkmode&0xfffffff8)|0x00000004;
	WR_MEM_32(CM_CLKMODE_DPLL_PER,clkmode);
	while((RD_MEM_32(CM_IDLEST_DPLL_PER) & 0x00000100 )!=0x00000100);

	clksel = clksel & (~0xFF0FFFFF);
	clksel = clksel | 0x04000000;  //SD divider = 4 for both OPP100 and OPP50
	clksel = clksel | ((M <<0x8) | N);
	WR_MEM_32(CM_CLKSEL_DPLL_PER,clksel);
	div_m2= 0xFFFFFF80 | M2;
	WR_MEM_32(CM_DIV_M2_DPLL_PER,div_m2);
	clkmode =(clkmode&0xfffffff8)|0x00000007;
	WR_MEM_32(CM_CLKMODE_DPLL_PER,clkmode);

	while((RD_MEM_32(CM_IDLEST_DPLL_PER) & 0x00000001 )!=0x00000001);

}

void DISP_PLL_Config(UWORD32 CLKIN,UWORD32 N,UWORD32 M,UWORD32 M2)
{
	UWORD32 clkmode,clksel,div_m2;


	clkmode=RD_MEM_32(CM_CLKMODE_DPLL_DISP);
	clksel= RD_MEM_32(CM_CLKSEL_DPLL_DISP);
	div_m2= RD_MEM_32(CM_DIV_M2_DPLL_DISP);

	clkmode =(clkmode&0xfffffff8)|0x00000004;
	WR_MEM_32(CM_CLKMODE_DPLL_DISP,clkmode);
	while((RD_MEM_32(CM_IDLEST_DPLL_DISP) & 0x00000100 )!=0x00000100);

	clksel = clksel & (~0x7FFFF);
	clksel = clksel | ((M <<0x8) | N);
	WR_MEM_32(CM_CLKSEL_DPLL_DISP,clksel);
	div_m2= 0xFFFFFFE0 | M2;
	WR_MEM_32(CM_DIV_M2_DPLL_DISP,div_m2);
	clkmode =(clkmode&0xfffffff8)|0x00000007;
	WR_MEM_32(CM_CLKMODE_DPLL_DISP,clkmode);

	while((RD_MEM_32(CM_IDLEST_DPLL_DISP) & 0x00000001 )!=0x00000001);
}

void Bypass_DISP_PLL()
{
	UWORD32 clkmode;

    clkmode=RD_MEM_32(CM_CLKMODE_DPLL_DISP);
    clkmode =(clkmode&0xfffffff8)|0x00000004;
	WR_MEM_32(CM_CLKMODE_DPLL_DISP,clkmode);
	while((RD_MEM_32(CM_IDLEST_DPLL_DISP) & 0x00000100 )!=0x00000100);
}

//##############################################################################
//##############################################################################
//                       DDR Configuration Section
//##############################################################################
//##############################################################################

//******************************************************************
//DDR3=400MHz
//OPP100
//******************************************************************
void DDR3_EMIF_Config()
{
    EMIF_PRCM_CLK_ENABLE();

    VTP_Enable();

 	PHY_Config_CMD();
 	PHY_Config_DATA();

    WR_MEM_32(DDR_CMD0_IOCTRL,DDR_IOCTRL_VALUE);
    WR_MEM_32(DDR_CMD1_IOCTRL,DDR_IOCTRL_VALUE);
    WR_MEM_32(DDR_CMD2_IOCTRL,DDR_IOCTRL_VALUE);
    WR_MEM_32(DDR_DATA0_IOCTRL,DDR_IOCTRL_VALUE);
    WR_MEM_32(DDR_DATA1_IOCTRL,DDR_IOCTRL_VALUE);

    //IO to work for DDR3
    WR_MEM_32(DDR_IO_CTRL, RD_MEM_32(DDR_IO_CTRL) & ~0x10000000 );

    //CKE controlled by EMIF/DDR_PHY
    WR_MEM_32(DDR_CKE_CTRL, RD_MEM_32(DDR_CKE_CTRL) | 0x00000001);

    WR_MEM_32(EMIF_DDR_PHY_CTRL_1_REG, ALLOPP_DDR3_READ_LATENCY);
    WR_MEM_32(EMIF_DDR_PHY_CTRL_1_SHDW_REG, ALLOPP_DDR3_READ_LATENCY);
    WR_MEM_32(EMIF_DDR_PHY_CTRL_2_REG, ALLOPP_DDR3_READ_LATENCY);

    WR_MEM_32(EMIF_SDRAM_TIM_1_REG,ALLOPP_DDR3_SDRAM_TIMING1);
    WR_MEM_32(EMIF_SDRAM_TIM_1_SHDW_REG,ALLOPP_DDR3_SDRAM_TIMING1);

    WR_MEM_32(EMIF_SDRAM_TIM_2_REG,ALLOPP_DDR3_SDRAM_TIMING2);
    WR_MEM_32(EMIF_SDRAM_TIM_2_SHDW_REG,ALLOPP_DDR3_SDRAM_TIMING2);

    WR_MEM_32(EMIF_SDRAM_TIM_3_REG,ALLOPP_DDR3_SDRAM_TIMING3);
    WR_MEM_32(EMIF_SDRAM_TIM_3_SHDW_REG,ALLOPP_DDR3_SDRAM_TIMING3);

    WR_MEM_32(EMIF_SDRAM_REF_CTRL_REG,ALLOPP_DDR3_REF_CTRL);
    WR_MEM_32(EMIF_SDRAM_REF_CTRL_SHDW_REG,ALLOPP_DDR3_REF_CTRL);
    WR_MEM_32(EMIF_ZQ_CONFIG_REG,ALLOPP_DDR3_ZQ_CONFIG);
    WR_MEM_32(EMIF_SDRAM_CONFIG_REG, ALLOPP_DDR3_SDRAM_CONFIG);
}


void PHY_Config_CMD()
{
   UWORD32 i=0;
   for(i=0;i<3;i++)
   {
	   WR_MEM_32(CMD0_REG_PHY_CTRL_SLAVE_RATIO_0 + (i*0x34),CMD_PHY_CTRL_SLAVE_RATIO);
	   WR_MEM_32(CMD0_REG_PHY_INVERT_CLKOUT_0    + (i*0x34),CMD_PHY_INVERT_CLKOUT);
   }
}

void PHY_Config_DATA()
{
	UWORD32 i;
	for(i=0;i<2;i++)
	{
        WR_MEM_32(DATA0_REG_PHY_RD_DQS_SLAVE_RATIO_0     + (i*0xA4),DATA_PHY_RD_DQS_SLAVE_RATIO);
        WR_MEM_32(DATA0_REG_PHY_WR_DQS_SLAVE_RATIO_0     + (i*0xA4),DATA_PHY_WR_DQS_SLAVE_RATIO);
        WR_MEM_32(DATA0_REG_PHY_FIFO_WE_SLAVE_RATIO_0    + (i*0xA4),DATA_PHY_FIFO_WE_SLAVE_RATIO);
        WR_MEM_32(DATA0_REG_PHY_WR_DATA_SLAVE_RATIO_0    + (i*0xA4),DATA_PHY_WR_DATA_SLAVE_RATIO);
	}
}

void EMIF_PRCM_CLK_ENABLE()
{
    /* Enable EMIF4 clocks*/
    WR_MEM_32(CM_PER_EMIF_CLKCTRL,0x02);
    /* Poll if module is functional */
    while(RD_MEM_32(CM_PER_EMIF_CLKCTRL)!= 0x02);
}

//************************************************************************
//VTP_Enable() routine                                                   *
//************************************************************************

void VTP_Enable()
{
      //clear the register
      WR_MEM_32(VTP_CTRL_REG ,0x0);
      //set filter bits to 011b
      WR_MEM_32(VTP_CTRL_REG ,0x6);
      //Write 1 to enable VTP
      WR_MEM_32(VTP_CTRL_REG ,(RD_MEM_32(VTP_CTRL_REG) | 0x00000040));
      //Write 0 to CLRZ bit
      WR_MEM_32(VTP_CTRL_REG ,(RD_MEM_32(VTP_CTRL_REG) & 0xFFFFFFFE));
      //Write 1 to CLRZ bit
      WR_MEM_32(VTP_CTRL_REG ,(RD_MEM_32(VTP_CTRL_REG) | 0x00000001));
     //Check for VTP ready bit
      while((RD_MEM_32(VTP_CTRL_REG) & 0x00000020) != 0x00000020);
}

