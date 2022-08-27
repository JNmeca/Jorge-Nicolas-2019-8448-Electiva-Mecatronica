/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : Cpu.c
**     Project     : Liffy
**     Processor   : MC9S08MP16VLF
**     Component   : MC9S08MP16_48
**     Version     : Component 01.001, Driver 01.40, CPU db: 3.00.026
**     Datasheet   : MC9S08MP16 Rev. 1 09/2009
**     Compiler    : CodeWarrior HCS08 C Compiler
**     Date/Time   : 2022-08-26, 19:56, # CodeGen: 5
**     Abstract    :
**         This component "MC9S08MP16_48" contains initialization 
**         of the CPU and provides basic methods and events for 
**         CPU core settings.
**     Settings    :
**
**     Contents    :
**         EnableInt  - void Cpu_EnableInt(void);
**         DisableInt - void Cpu_DisableInt(void);
**
**     Copyright : 1997 - 2014 Freescale Semiconductor, Inc. 
**     All Rights Reserved.
**     
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**     
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**     
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**     
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**     
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**     
**     http: www.freescale.com
**     mail: support@freescale.com
** ###################################################################*/
/*!
** @file Cpu.c
** @version 01.40
** @brief
**         This component "MC9S08MP16_48" contains initialization 
**         of the CPU and provides basic methods and events for 
**         CPU core settings.
*/         
/*!
**  @addtogroup Cpu_module Cpu module documentation
**  @{
*/         

/* MODULE Cpu. */

#pragma MESSAGE DISABLE C4002 /* WARNING C4002: Result not used is ignored */

#include "Relay1.h"
#include "Relay2.h"
#include "Relay3.h"
#include "Relay4.h"
#include "Motor1.h"
#include "Motor2.h"
#include "Motor3.h"
#include "Motor4.h"
#include "DIP1.h"
#include "DIP2.h"
#include "Nivel.h"
#include "Luz1.h"
#include "Luz2.h"
#include "DHT11.h"
#include "Measure_An.h"
#include "Interrupt.h"
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Events.h"
#include "Cpu.h"


/* Global variables */
volatile byte CCR_reg;                 /* Current CCR register */
volatile byte CCR_lock;                /* Nesting level of critical regions */

/*Definition of global shadow variables*/
byte Shadow_PTB;


/*
** ===================================================================
**     Method      :  Cpu_Interrupt (component MC9S08MP16_48)
**
**     Description :
**         The method services unhandled interrupt vectors.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
ISR(Cpu_Interrupt)
{
  /* This code can be changed using the CPU component property "Build Options / Unhandled int code" */
  /*lint -save -e950 Disable MISRA rule (1.1) checking. */
  asm(BGND);
  /*lint -restore Enable MISRA rule (1.1) checking. */
}


/*
** ===================================================================
**     Method      :  Cpu_DisableInt (component MC9S08MP16_48)
**     Description :
**         Disables maskable interrupts
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void Cpu_DisableInt(void)

**      This method is implemented as macro in the header module. **
*/

/*
** ===================================================================
**     Method      :  Cpu_EnableInt (component MC9S08MP16_48)
**     Description :
**         Enables maskable interrupts
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void Cpu_EnableInt(void)

**      This method is implemented as macro in the header module. **
*/

/*
** ===================================================================
**     Method      :  _EntryPoint (component MC9S08MP16_48)
**
**     Description :
**         Initializes the whole system like timing and so on. At the end 
**         of this function, the C startup is invoked to initialize stack,
**         memory areas and so on.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
extern void _Startup(void);            /* Forward declaration of external startup function declared in file Start12.c */

#pragma NO_FRAME
#pragma NO_EXIT
void _EntryPoint(void)
{
  /* ### MC9S08MP16_48 "Cpu" init code ... */
  /*  PE initialization code after reset */
  /* Common initialization of the write once registers */
  /* SOPT1: COPT=0,STOPE=0,SPIFE=0,ACIC2=0,ACIC1=0,BKGDPE=1,RSTPE=1 */
  setReg8(SOPT1, 0x03U);                
  /* SPMSC1: LVWF=0,LVWACK=0,LVWIE=0,LVDRE=1,LVDSE=1,LVDE=1,??=0,BGBE=0 */
  setReg8(SPMSC1, 0x1CU);               
  /* SPMSC2: ??=0,??=0,LVDV=0,LVWV=0,PPDF=0,PPDACK=0,??=0,PPDC=0 */
  setReg8(SPMSC2, 0x00U);               
  /*  System clock initialization */
  /*lint -save  -e923 Disable MISRA rule (11.3) checking. */
  if (*(uint8_t*)0xFFAFU != 0xFFU) {   /* Test if the device trim value is stored on the specified address */
    ICSTRM = *(uint8_t*)0xFFAFU;       /* Initialize ICSTRM register from a non volatile memory */
    ICSSC = (uint8_t)((*(uint8_t*)0xFFAEU) & (uint8_t)0x01U); /* Initialize ICSSC register from a non volatile memory */
  }
  /*lint -restore Enable MISRA rule (11.3) checking. */
  /* ICSC1: CLKS=0,RDIV=0,IREFS=1,IRCLKEN=1,IREFSTEN=0 */
  setReg8(ICSC1, 0x06U);               /* Initialization of the ICS control register 1 */ 
  /* ICSC2: BDIV=1,RANGE=0,HGO=0,LP=0,EREFS=0,ERCLKEN=0,EREFSTEN=0 */
  setReg8(ICSC2, 0x40U);               /* Initialization of the ICS control register 2 */ 
  while(ICSSC_IREFST == 0U) {          /* Wait until the source of reference clock is internal clock */
  }
  /* ICSSC: DRST_DRS=0,DMX32=0 */
  clrReg8Bits(ICSSC, 0xE0U);           /* Initialization of the ICS status and control */ 
  while((ICSSC & 0xC0U) != 0x00U) {    /* Wait until the FLL switches to Low range DCO mode */
  }

  /*** End of PE initialization code after reset ***/
  /*lint -save  -e950 Disable MISRA rule (1.1) checking. */
  __asm   jmp _Startup ;               /* Jump to C startup code */
  /*lint -restore Enable MISRA rule (1.1) checking. */
}

/*
** ===================================================================
**     Method      :  PE_low_level_init (component MC9S08MP16_48)
**
**     Description :
**         Initializes components and provides common register 
**         initialization. The method is called automatically as a part 
**         of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void PE_low_level_init(void)
{
  #ifdef PEX_RTOS_INIT
    PEX_RTOS_INIT();                   /* Initialization of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /* SCGC1: FTM2=1,FTM1=1,MTIM=1,RTC=1,PDB=1,CMPDAC3=1,CMPDAC2=1,CMPDAC1=1 */
  setReg8(SCGC1, 0xFFU);                
  /* SCGC2: DBG=1,FLS=1,KBI=1,ADC=1,SCI=1,SPI=1,IIC=1,PGA=1 */
  setReg8(SCGC2, 0xFFU);                
  /* Common initialization of the CPU registers */
  /* PTCD: PTCD6=0,PTCD5=0,PTCD4=0,PTCD3=0,PTCD2=0,PTCD1=0,PTCD0=0 */
  clrReg8Bits(PTCD, 0x7FU);             
  /* PTCPE: PTCPE6=0,PTCPE5=0,PTCPE4=0,PTCPE3=0,PTCPE2=0,PTCPE1=0,PTCPE0=0 */
  clrReg8Bits(PTCPE, 0x7FU);            
  /* PTCDD: PTCDD6=1,PTCDD5=1,PTCDD4=1,PTCDD3=1,PTCDD2=1,PTCDD1=1,PTCDD0=1 */
  setReg8Bits(PTCDD, 0x7FU);            
  /* PTBD: PTBD5=1,PTBD4=0 */
  clrSetReg8Bits(PTBD, 0x10U, 0x20U);   
  /* PTBPE: PTBPE6=0,PTBPE5=1,PTBPE4=0 */
  clrSetReg8Bits(PTBPE, 0x50U, 0x20U);  
  /* PTBDD: PTBDD6=0,PTBDD5=1,PTBDD4=1 */
  clrSetReg8Bits(PTBDD, 0x40U, 0x30U);  
  /* PTAD: PTAD7=0,PTAD6=0 */
  clrReg8Bits(PTAD, 0xC0U);             
  /* PTAPE: PTAPE7=0,PTAPE6=0,PTAPE5=0,PTAPE4=0 */
  clrReg8Bits(PTAPE, 0xF0U);            
  /* PTADD: PTADD7=1,PTADD6=1,PTADD5=0,PTADD4=0 */
  clrSetReg8Bits(PTADD, 0x30U, 0xC0U);  
  /* APCTL1: ADPC2=1,ADPC1=1,ADPC0=1 */
  setReg8Bits(APCTL1, 0x07U);           
  /* PTASE: PTASE7=0,PTASE6=0,PTASE5=0,PTASE4=0,PTASE3=0,PTASE2=0,PTASE1=0,PTASE0=0 */
  setReg8(PTASE, 0x00U);                
  /* PTBSE: PTBSE7=0,PTBSE6=0,PTBSE5=0,PTBSE4=0,PTBSE3=0,PTBSE2=0,PTBSE1=0,PTBSE0=0 */
  setReg8(PTBSE, 0x00U);                
  /* PTCSE: PTCSE7=0,PTCSE6=0,PTCSE5=0,PTCSE4=0,PTCSE3=0,PTCSE2=0,PTCSE1=0,PTCSE0=0 */
  setReg8(PTCSE, 0x00U);                
  /* PTDSE: PTDSE7=0,PTDSE6=0,PTDSE5=0,PTDSE4=0,PTDSE3=0,PTDSE2=0,PTDSE1=0,PTDSE0=0 */
  setReg8(PTDSE, 0x00U);                
  /* PTESE: PTESE6=0,PTESE5=0,PTESE4=0,PTESE3=0,PTESE2=0,PTESE1=0,PTESE0=0 */
  clrReg8Bits(PTESE, 0x7FU);            
  /* PTFSE: PTFSE2=0,PTFSE1=0,PTFSE0=0 */
  clrReg8Bits(PTFSE, 0x07U);            
  /* PTADS: PTADS7=1,PTADS6=1,PTADS5=1,PTADS4=1,PTADS3=1,PTADS2=1,PTADS1=1,PTADS0=1 */
  setReg8(PTADS, 0xFFU);                
  /* PTBDS: PTBDS7=1,PTBDS6=1,PTBDS5=1,PTBDS4=1,PTBDS3=1,PTBDS2=1,PTBDS1=1,PTBDS0=1 */
  setReg8(PTBDS, 0xFFU);                
  /* PTCDS: PTCDS7=1,PTCDS6=1,PTCDS5=1,PTCDS4=1,PTCDS3=1,PTCDS2=1,PTCDS1=1,PTCDS0=1 */
  setReg8(PTCDS, 0xFFU);                
  /* PTDDS: PTDDS7=1,PTDDS6=1,PTDDS5=1,PTDDS4=1,PTDDS3=1,PTDDS2=1,PTDDS1=1,PTDDS0=1 */
  setReg8(PTDDS, 0xFFU);                
  /* PTEDS: ??=0,PTEDS6=1,PTEDS5=1,PTEDS4=1,PTEDS3=1,PTEDS2=1,PTEDS1=1,PTEDS0=1 */
  setReg8(PTEDS, 0x7FU);                
  /* PTFDS: ??=0,??=0,??=0,??=0,??=0,PTFDS2=1,PTFDS1=1,PTFDS0=1 */
  setReg8(PTFDS, 0x07U);                
  /* ILRS7: ILR31=0,ILR30=0,ILR29=0,ILR28=0 */
  setReg8(ILRS7, 0x00U);                
  /* ILRS6: ILR27=0,ILR26=0,ILR25=0,ILR24=0 */
  setReg8(ILRS6, 0x00U);                
  /* ILRS5: ILR23=0,ILR22=0,ILR21=0,ILR20=0 */
  setReg8(ILRS5, 0x00U);                
  /* ILRS4: ILR19=0,ILR18=2,ILR17=0,ILR16=0 */
  setReg8(ILRS4, 0x20U);                
  /* ILRS3: ILR15=2,ILR14=0,ILR13=0,ILR12=0 */
  setReg8(ILRS3, 0x80U);                
  /* ILRS2: ILR11=0,ILR10=0,ILR9=0,ILR8=0 */
  setReg8(ILRS2, 0x00U);                
  /* ILRS1: ILR7=0,ILR6=0,ILR5=0,ILR4=0 */
  setReg8(ILRS1, 0x00U);                
  /* ILRS0: ILR3=0,ILR2=0,ILR1=0,ILR0=0 */
  setReg8(ILRS0, 0x00U);                
  /* IPCSC: IPCE=1,??=0,PSE=0,PSF=0,PULIPM=0,??=0,IPM=0 */
  setReg8(IPCSC, 0x80U);                
  /* ### Shared modules init code ... */
  /* ### BitIO "Relay1" init code ... */
  /* ### BitIO "Relay2" init code ... */
  /* ### BitIO "Relay3" init code ... */
  /* ### BitIO "Relay4" init code ... */
  /* ### BitIO "Motor1" init code ... */
  /* ### BitIO "Motor2" init code ... */
  /* ### BitIO "Motor3" init code ... */
  /* ### BitIO "Motor4" init code ... */
  /* ### BitIO "DIP1" init code ... */
  /* ### BitIO "DIP2" init code ... */
  /* ### BitIO "Nivel" init code ... */
  /* ### BitIO "Luz1" init code ... */
  /* ### BitIO "Luz2" init code ... */
  /* ### BitIO "DHT11" init code ... */
  Shadow_PTB |= (byte)0x20U;           /* Initialize pin shadow variable bit */
  /* ###  "Measure_An" init code ... */
  Measure_An_Init();
  /* ### TimerInt "Interrupt" init code ... */
  Interrupt_Init();
  CCR_lock = (byte)0;
  __EI();                              /* Enable interrupts */
}

/*lint -save  -e950 Disable MISRA rule (1.1) checking. */
/* Initialization of the CPU registers in FLASH */
/* NVPROT: FPS7=1,FPS6=1,FPS5=1,FPS4=1,FPS3=1,FPS2=1,FPS1=1,FPDIS=1 */
static const uint8_t NVPROT_INIT @0x0000FFBDU = 0xFFU;
/* NVOPT: KEYEN=0,FNORED=1,??=1,??=1,??=1,??=1,SEC01=1,SEC00=0 */
static const uint8_t NVOPT_INIT @0x0000FFBFU = 0x7EU;
/*lint -restore Enable MISRA rule (1.1) checking. */

/* END Cpu. */

/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.09]
**     for the Freescale HCS08 series of microcontrollers.
**
** ###################################################################
*/
