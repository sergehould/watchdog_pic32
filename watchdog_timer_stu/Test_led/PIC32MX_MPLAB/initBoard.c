/***********************************************************************************************
*
*
* FileName:  initBoard.c      
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author        	Date            Version     Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Serge Hould      14 Jan. 2021		v1.0.0      Setup for PIC32    
* 
*
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#include "include/initBoard.h"
#include "include/public.h"

 // Configuration Bit settings
// SYSCLK = 80 MHz 
//(8MHz Crystal/ FPLLIDIV * FPLLMUL / FPLLODIV)
// PBCLK = 40 MHz
// Primary Osc w/PLL (HS+PLL)
// WDT OFF, Peripheral Bus is CPU clock÷8
// Other options are default as per datasheet
// see file:C:\Program Files (x86)\Microchip\xc32\v1.40\docs\config_docs\32mx795f512l.html
 

#pragma config FPLLMUL = MUL_20
#pragma config FPLLIDIV = DIV_2
#pragma config FPLLODIV = DIV_1 
#pragma config POSCMOD = HS, FNOSC = PRIPLL
#pragma config FPBDIV = DIV_2   // PBCLK = SYSCLK/DIV_2
//#pragma config WDTPS =  
#pragma config FWDTEN =  OFF 

/* Sets up the IOs */
void initIO(void)
{
    /* LEDs */
    TRISAbits.TRISA6 = 0; // LED D9
    TRISAbits.TRISA7 = 0; // LED D10
       
}

/* Sets up the hardware */
void prvSetupHardware( void ){
	/* Configure the hardware for maximum performance. */
	vHardwareConfigurePerformance();
	/* Setup to use the external interrupt controller. */
	vHardwareUseMultiVectoredInterrupts();
	portDISABLE_INTERRUPTS();
}