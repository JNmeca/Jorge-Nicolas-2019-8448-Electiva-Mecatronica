/* ###################################################################
**     Filename    : Events.h
**     Project     : Liffy
**     Processor   : MC9S08MP16VLF
**     Component   : Events
**     Version     : Driver 01.02
**     Compiler    : CodeWarrior HCS08 C Compiler
**     Date/Time   : 2022-08-24, 00:13, # CodeGen: 0
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file Events.h
** @version 01.02
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         

#ifndef __Events_H
#define __Events_H
/* MODULE Events */

#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
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


void Interrupt_OnInterrupt(void);
/*
** ===================================================================
**     Event       :  Interrupt_OnInterrupt (module Events)
**
**     Component   :  Interrupt [TimerInt]
**     Description :
**         When a timer interrupt occurs this event is called (only
**         when the component is enabled - <Enable> and the events are
**         enabled - <EnableEvent>). This event is enabled only if a
**         <interrupt service/event> is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void Measure_An_OnEnd(void);
/*
** ===================================================================
**     Event       :  Measure_An_OnEnd (module Events)
**
**     Component   :  Measure_An [ADC]
**     Description :
**         This event is called after the measurement (which consists
**         of <1 or more conversions>) is/are finished.
**         The event is available only when the <Interrupt
**         service/event> property is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

/* END Events */
#endif /* __Events_H*/

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
