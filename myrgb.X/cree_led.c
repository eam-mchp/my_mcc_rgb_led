/*******************************************************************************
  CREE LED

  Company:
    Microchip Technology Inc.

  File Name:
    cree_led.c

  Summary:
    Contains the functional implementation of CREE LED.

  Description:
    This file contains the functional implementation of CREE LED.
*******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2014 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED AS IS WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 *******************************************************************************/
//DOM-IGNORE-END
#include "app.h"

static bool mFlagOC1On;
static bool mFlagOC2On;
static bool mFlagOC3On;
static void LEDColorDutySet(int Red, int Green, int Blue);


void LEDColorSet(int Red, int Green, int Blue)
{
    int NewRed,NewGreen,NewBlue;

    NewRed = ((Red*100)/255);
    NewGreen = ((Green*100)/255);
    NewBlue = ((Blue*100)/255);

    LEDColorDutySet( NewRed,  NewGreen,  NewBlue);
}

static void LEDColorDutySet(int Red, int Green, int Blue)
{
    float TimerVal;
    float Psteps ;
    float NewRed,NewGreen,NewBlue;
//    float Temp= 0;
    int OcRed = mFlagOC1On;
    int OcGreen = mFlagOC2On;
    int OcBlue = mFlagOC3On;

    /* PWM cannot exceed Period, Dynamic PWM steps per code */
    TimerVal= 0xFFFF;//TMR2_Period16BitGet();//TimerVal = PLIB_TMR_Period16BitGet(APP_TMR_ID_FOR_OC);
    Psteps = TimerVal/100;

    /* takes values and turns them into a %*/
    NewRed  = ((100-Red) * Psteps);
    NewGreen  = ((100-Green) * Psteps);
    NewBlue  = ((100-Blue) * Psteps);

    if (NewRed < 0x03)
    {
        /*turn off PWM if to low or below 0*/
        //PLIB_OC_Disable(APP_RGB_LED_RED_OC_ID);
        OC3_Stop();
        mFlagOC1On = 0;
    }

    else
    {

        if(OcRed == 0)
        {
            /* If PWM is off tun it back on*/
            //PLIB_OC_Enable(APP_RGB_LED_RED_OC_ID);
            OC3_Start();
            mFlagOC1On = 1;
        }
        if (NewRed > TimerVal)
        {
            /*if the new vaule exceeds the Period set to period (max)*/
            NewRed = TimerVal;
        }
        /*LED is active LOW, correct for postive value*/
//        Temp = ((100-Red) * Psteps);
        /* update PWM register */
        //PLIB_OC_PulseWidth16BitSet(APP_RGB_LED_RED_OC_ID, NewRed);
        OC3_PWMPulseWidthSet(NewRed);
    }

    if (NewGreen < 0x03)
    {
        //PLIB_OC_Disable(APP_RGB_LED_GREEN_OC_ID);
        OC4_Stop();
        mFlagOC2On = 0;
    }
    else
    {
        if(OcGreen == 0)
        {
            //PLIB_OC_Enable(APP_RGB_LED_GREEN_OC_ID);
            OC4_Start();
            mFlagOC2On = 1;
        }
        if (NewGreen > TimerVal)
        {
            NewGreen = TimerVal;
        }
        //PLIB_OC_PulseWidth16BitSet(APP_RGB_LED_GREEN_OC_ID, NewGreen);
        OC4_PWMPulseWidthSet(NewGreen);
    }

    if (NewBlue < 0x03)
    {
        //PLIB_OC_Disable(APP_RGB_LED_BLUE_OC_ID);
        OC5_Stop();
        mFlagOC3On = 0;
    }
    else
    {
        if(OcBlue == 0)
        {
            //PLIB_OC_Enable(APP_RGB_LED_BLUE_OC_ID);
              OC5_Start();
            mFlagOC3On = 1;
        }
        if(NewBlue > TimerVal)
        {
            NewBlue = TimerVal;
        }
        //PLIB_OC_PulseWidth16BitSet(APP_RGB_LED_BLUE_OC_ID, NewBlue);
        OC5_PWMPulseWidthSet(NewBlue);
    }

}
/*******************************************************************************
 End of File
 */