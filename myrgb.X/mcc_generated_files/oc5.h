/**
  OC5 Generated Driver API Header File

  @Company
    Microchip Technology Inc.

  @File Name
    oc5.h

  @Summary
    This is the generated header file for the OC5 driver using MPLAB(c) Code Configurator

  @Description
    This header file provides APIs for driver for OC5.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 4.15
        Device            :  PIC32MX470F512H
        Driver Version    :  0.5
    The generated drivers are tested against the following:
        Compiler          :  XC32 1.40
        MPLAB 	          :  MPLAB X 3.40
*/

/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

#ifndef _OC5_H
#define _OC5_H

/**
  Section: Included Files
*/

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
    
#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif

/**
  Section: Interface Routines
*/

/**
  @Summary
    This function initializes OC instance : 5

  @Description
    This routine initializes the OC5 driver instance for : 5
    index, making it ready for clients to open and use it.
    This routine must be called before any other OC5 routine is called.
	
  @Preconditions
    None.

  @Param
    None.

  @Returns
    None.

  @Example
    <code>
    uint16_t value;
    value = 0x1000;

    OC5_Initialize();  
    OC5_Stop();    
    OC5_PWMPulseWidthSet( value );  
    OC5_Start();

    while(1)
    {
        faultStat =  OC5_FaultStatusGet( );

        if(faultStat)
        {
            break;
        }
        
        // Do other tasks
    }
    </code>

*/

void OC5_Initialize (void);

/**
  @Summary
    Maintains the driver's state machine and implements its ISR

  @Description
    This routine is used to maintain the driver's internal state
    machine and implement its ISR for interrupt-driven implementations.
  
  @Preconditions
    None.

  @Param
    None.

  @Returns
    None.

  @Example
    <code>
    while (true)
    {
        OC5_Tasks();

        // Do other tasks
    }
    </code>
    
*/

void OC5_Tasks( void );

/**
  @Summary
    Enables the OC module.

  @Description
    This routine enables the OC module.

  @Preconditions
    OC5_Initialize function should have been called 

  @Param
    None.

  @Returns
    None.

  @Example 
    Refer to OC5_Initialize() for an example	 
*/

void OC5_Start( void );

/**
  @Summary
    Disables the OC module.

  @Description
    This routine disables the OC module.

  @Preconditions
    OC5_Initialize function should have been called 

  @Param
    None.

  @Returns
    None.

  @Example 
    Refer to OC5_Initialize() for an example
*/

void OC5_Stop( void );

/**
  @Summary
    Sets the primary compare value.

  @Description
    This routine sets the primary compare value.

  @Preconditions
    OC5_Initialize function should have been called 

  @Param
    None.

  @Returns
    None.

  @Example 
    <code>
        uint16_t value = 0x1000;
        OC5_SingleCompareValueSet( value );
    <code>
*/

void OC5_SingleCompareValueSet( uint16_t value );

/**
  @Summary
    Sets the primary and secondary compare value.

  @Description
    This routine sets the primary and secondary compare value.

  @Preconditions
    OC5_Initialize function should have been called 

  @Param
    priVal - 32/16 bit primary compare value.
    secVal - 32/16 bit primary compare value.	

  @Returns
    None.

  @Example 
    <code>
        uint16_t priVal = 0x1000;
        uint16_t secVal = 0x2000;
        OC5_DualCompareValueSet( priVal,secVal );
    <code>
  	
*/

void OC5_DualCompareValueSet( uint16_t priVal, uint16_t secVal );

/**
  @Summary
    Sets the Pulse width for PWM mode.

  @Description
    This routine sets the Pulse Width for PWM mode.

  @Preconditions
    OC5_Initialize function should have been called 

  @Param
    value - 32/16 bit compare value.	

  @Returns
    None.

  @Example 
    <code>
        uint16_t value = 0x2000;
        OC5_PWMPulseWidthSet( value );
    <code> 
 	
*/

void OC5_PWMPulseWidthSet( uint16_t value );

/**
  @Summary
    Gets the status of the PWM fault condition occurrence.

  @Description
    This routine gets the status of the PWM fault condition occurrence.
  
  @Preconditions
    OC5_Initialize function should have been called 

  @Param
    None

  @Returns
    boolean value describing the occurrence of the fault condition.
    true  : When the fault has occurred.
    false : When the fault has not occurred.
	
  @Example 
    Refer to OC5_Initialize() for an example 
 
*/

bool OC5_PWMFaultStatusGet( void );

#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif

#endif //_OC5_H
    
/**
 End of File
*/
