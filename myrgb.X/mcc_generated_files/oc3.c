
/**
  OC3 Generated Driver API Source File

  @Company
    Microchip Technology Inc.

  @File Name
    oc3.c

  @Summary
    This is the generated source file for the OC3 driver using MPLAB(c) Code Configurator

  @Description
    This source file provides APIs for driver for OC3.
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
#include "oc3.h"

/**
  Section: Driver Interface
*/

void OC3_Initialize (void)
{
    // OC3RS 5;     
    OC3RS = 0x5;
    
    // OC3R 5;     
    OC3R = 0x5;
    
    // OC32 16-bit Mode; OCM Dual Compare Continuous Pulse mode; SIDL disabled; OCTSEL TMR2; ON enabled;     
    OC3CON = 0x8005;
	
}

void OC3_Tasks( void )
{
    if(IFS0bits.OC3IF)
    {
        IFS0bits.OC3IF = 0;
    }
}

void OC3_Start( void )
{
    OC3CONbits.ON = 1;
}

void OC3_Stop( void )
{
    OC3CONbits.ON = 0;
}

void OC3_SingleCompareValueSet( uint16_t value )
{
    OC3R = value;
}

void OC3_DualCompareValueSet( uint16_t priVal, uint16_t secVal )
{
    OC3R = priVal;
	
    OC3RS = secVal;
}

void OC3_PWMPulseWidthSet( uint16_t value )
{
    OC3RS = value;
}

bool OC3_PWMFaultStatusGet()
{ 
    /* Return the status of the fault condition */
    return(OC3CONbits.OCFLT);
}

/**
 End of File
*/
