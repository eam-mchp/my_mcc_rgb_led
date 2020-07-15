
/**
  OC4 Generated Driver API Source File

  @Company
    Microchip Technology Inc.

  @File Name
    oc4.c

  @Summary
    This is the generated source file for the OC4 driver using MPLAB(c) Code Configurator

  @Description
    This source file provides APIs for driver for OC4.
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

/**
  Section: Included Files
*/
#include <xc.h>
#include "oc4.h"

/**
  Section: Driver Interface
*/

void OC4_Initialize (void)
{
    // OC4RS 5;     
    OC4RS = 0x5;
    
    // OC4R 5;     
    OC4R = 0x5;
    
    // OC32 16-bit Mode; OCM Dual Compare Continuous Pulse mode; SIDL disabled; OCTSEL TMR2; ON enabled;     
    OC4CON = 0x8005;
	
}

void OC4_Tasks( void )
{
    if(IFS0bits.OC4IF)
    {
        IFS0bits.OC4IF = 0;
    }
}

void OC4_Start( void )
{
    OC4CONbits.ON = 1;
}

void OC4_Stop( void )
{
    OC4CONbits.ON = 0;
}

void OC4_SingleCompareValueSet( uint16_t value )
{
    OC4R = value;
}

void OC4_DualCompareValueSet( uint16_t priVal, uint16_t secVal )
{
    OC4R = priVal;
	
    OC4RS = secVal;
}

void OC4_PWMPulseWidthSet( uint16_t value )
{
    OC4RS = value;
}

bool OC4_PWMFaultStatusGet()
{ 
    /* Return the status of the fault condition */
    return(OC4CONbits.OCFLT);
}

/**
 End of File
*/
