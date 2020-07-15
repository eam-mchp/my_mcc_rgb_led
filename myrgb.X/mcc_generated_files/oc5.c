
/**
  OC5 Generated Driver API Source File

  @Company
    Microchip Technology Inc.

  @File Name
    oc5.c

  @Summary
    This is the generated source file for the OC5 driver using MPLAB(c) Code Configurator

  @Description
    This source file provides APIs for driver for OC5.
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
#include "oc5.h"

/**
  Section: Driver Interface
*/

void OC5_Initialize (void)
{
    // OC5RS 5;     
    OC5RS = 0x5;
    
    // OC5R 5;     
    OC5R = 0x5;
    
    // OC32 16-bit Mode; OCM Dual Compare Continuous Pulse mode; SIDL disabled; OCTSEL TMR2; ON enabled;     
    OC5CON = 0x8005;
	
}

void OC5_Tasks( void )
{
    if(IFS0bits.OC5IF)
    {
        IFS0bits.OC5IF = 0;
    }
}

void OC5_Start( void )
{
    OC5CONbits.ON = 1;
}

void OC5_Stop( void )
{
    OC5CONbits.ON = 0;
}

void OC5_SingleCompareValueSet( uint16_t value )
{
    OC5R = value;
}

void OC5_DualCompareValueSet( uint16_t priVal, uint16_t secVal )
{
    OC5R = priVal;
	
    OC5RS = secVal;
}

void OC5_PWMPulseWidthSet( uint16_t value )
{
    OC5RS = value;
}

bool OC5_PWMFaultStatusGet()
{ 
    /* Return the status of the fault condition */
    return(OC5CONbits.OCFLT);
}

/**
 End of File
*/
