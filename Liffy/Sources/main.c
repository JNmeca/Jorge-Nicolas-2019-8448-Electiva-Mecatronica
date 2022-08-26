/* ###################################################################
**     Filename    : main.c
**     Project     : Liffy
**     Processor   : MC9S08MP16VLF
**     Version     : Driver 01.12
**     Compiler    : CodeWarrior HCS08 C Compiler
**     Date/Time   : 2022-08-24, 00:13, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.12
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "Relay1.h"
#include "Relay2.h"
#include "Relay3.h"
#include "Relay4.h"
/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
//DEFINE Valor de los Estados
#define STATE_INIT				0	//Estado Inicial
#define STATE_REVISION			1	//Estado Revisión
#define STATE_MEASURE			2	//Estado Medición
#define STATE_HEALTH			3	//Estado Salud Planta
#define STATE_MAINTENANCE		4	//Estado Mantenimiento 
#define STATE_ERROR				5	//Estado Error

//Set
#define ON_Relay 				1
#define OFF_Relay				0

//Prototipos de los Estados
unsigned char F_STATE_INIT(void);			//Estado Inicial
unsigned char F_STATE_REVISION(void);		//Estado Revisión
unsigned char F_STATE_MEASURE(void);		//Estado Medición
unsigned char F_STATE_HEALTH(void);			//Estado Salud Planta
unsigned char F_STATE_MAINTENANCE(void);	//Estado Mantenimiento 
unsigned char F_STATE_ERROR(void);			//Estado Error

unsigned char ESTADO_ACTUAL = STATE_INIT;
unsigned char ESTADO_SIGUIENTE = STATE_INIT;
unsigned char ESTADO_PASADO = STATE_INIT;
void main(void)
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  /* For example: for(;;) { } */
  ESTADO_SIGUIENTE = F_STATE_INIT();
  for (;;) 
  {
	if (ESTADO_SIGUIENTE == STATE_REVISION) 
	{
		ESTADO_SIGUIENTE = F_STATE_REVISION();
	}
	
	if (ESTADO_SIGUIENTE == STATE_MEASURE) 
	{
		ESTADO_SIGUIENTE = F_STATE_MEASURE();	
	}
	
	if (ESTADO_SIGUIENTE == STATE_HEALTH) 
	{
		ESTADO_SIGUIENTE = F_STATE_HEALTH();
	}
	
	if (ESTADO_SIGUIENTE == STATE_MAINTENANCE) 
	{
		ESTADO_SIGUIENTE = F_STATE_MAINTENANCE();
	}
	
	if (ESTADO_SIGUIENTE == STATE_ERROR) 
	{
		ESTADO_SIGUIENTE = F_STATE_ERROR();
	}
  }
  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
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

unsigned char F_STATE_INIT(void)		//Estado Inicial
{
	Relay1_PutVal(0);
	
}

unsigned char F_STATE_REVISION(void)	//Estado Revisión
{
	
}

unsigned char F_STATE_MEASURE(void)		//Estado Medición
{
	
}
unsigned char F_STATE_HEALTH(void)		//Estado Salud Planta
{
		
}
unsigned char F_STATE_MAINTENANCE(void)	//Estado Mantenimiento 
{
	
}
unsigned char F_STATE_ERROR(void)		//Estado Error
{
	
}
