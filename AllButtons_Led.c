/*
 * File:   newmain.c
 * Author: Harsh
 *
 * 
 */

/******************************************************************************
 * Software License Agreement
 *
 * Copyright � 2011 Microchip Technology Inc.  All rights reserved.
 * Microchip licenses to you the right to use, modify, copy and distribute
 * Software only when embedded on a Microchip microcontroller or digital
 * signal controller, which is integrated into your product or third party
 * product (pursuant to the sublicense terms in the accompanying license
 * agreement).
 *
 * You should refer to the license agreement accompanying this Software
 * for additional information regarding your rights and obligations.
 *
 * SOFTWARE AND DOCUMENTATION ARE PROVIDED ìAS ISî WITHOUT WARRANTY OF ANY
 * KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY
 * OF MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR
 * PURPOSE. IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR
 * OBLIGATED UNDER CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION,
 * BREACH OF WARRANTY, OR OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT
 * DAMAGES OR EXPENSES INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL,
 * INDIRECT, PUNITIVE OR CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA,
 * COST OF PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY
 * CLAIMS BY THIRD PARTIES (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF),
 * OR OTHER SIMILAR COSTS.
 *
 *****************************************************************************/


#include <xc.h>


//	Function Prototypes
int main(void);

int main(void) {
// //this one works for all 5 led 
    asm("nop"); 
    TRISB = 0;  // all port B is output - Led here 
    TRISA = 0;  // all port A is output - Led here
    TRISBbits.TRISB7 = 1; // RB7 as input on B register button input 1 - All lights
    TRISBbits.TRISB8 = 1; // RB8 as input on B register button input 2 - Only Green 
    
    TRISBbits.TRISB2 = 1; // RB2 as input on B register button input 3 - Only Blue
    ANSELBbits.ANSB2 = 0; // RB2 has analog capabilities, set ANSEL to zero analog off.
   
    // LATBbits.LATB3 for more direct control
     while(1){
         // ---------------->>> Only Blue Lights - STUCK HERE
         if(PORTBbits.RB2 == 1) {
         PORTBbits.RB3 = 1; 
         PORTBbits.RB14 = 1;
         PORTBbits.RB11 = 1;
//         LATBbits.LATB3 = 1; 
//         LATBbits.LATB14 = 1; 
//         LATBbits.LATB11 = 1; 
         }
         else if ( PORTBbits.RB2 == 0) {
         PORTBbits.RB3 = 0;
         PORTBbits.RB14 = 0;
         PORTBbits.RB11 = 0;
//         LATBbits.LATB3 = 0; 
//         LATBbits.LATB14 = 0; 
//         LATBbits.LATB11 = 0;
         }
         
         // ---------------->>> All Lights
         if(PORTBbits.RB7==1   ) {
         
         PORTB = 0xffff; 
          }
         else if(PORTBbits.RB7==0  ) {
         PORTB = 0x0000;
         
         //----------------->>> Only Green Lights
         }
         if(PORTBbits.RB8 == 1) {
         PORTBbits.RB15 = 1; 
         PORTBbits.RB13 = 1;
         PORTBbits.RB10 = 1;
         }
         else if ( PORTBbits.RB8 == 0) {
         PORTBbits.RB15 = 0;
         PORTBbits.RB13 = 0;
         PORTBbits.RB10 = 0;
         }
     
     }
    
    /*
     Control specific bit using 
     
    PORTBbits.RB15 = 1; RB5 on 
    PORTBbits.RB15 = 0; RB5 off
     * 
     * control entire PORTB = 0xff00; on all 5 led
     * PORTB = 0x0000; off all led
     * 
     */
    return (0); 
}



