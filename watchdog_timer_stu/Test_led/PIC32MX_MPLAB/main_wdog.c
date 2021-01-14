/* ***************************************************************************
 * File: main.c
 * Description: Main source file for all Embedded Operating Systems labs.
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Author        	Date      		Comments on this revision
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * SH               Jan 2019        V1.0.0    
 * SH               17 Dec 2019     V1.1.0  Add i2c and console libraries                             
 *****************************************************************************/

/* Standard includes. */
#include <stdio.h>
/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "croutine.h"

//Library includes
#include "include/console.h"
#include "include/adc.h"
#include "include/public.h"
#include "include/initBoard.h"
#include "include/Tick4.h"   
#include "include/i2c1.h"

/* Prototypes for the standard FreeRTOS callback/hook functions implemented within this file. */
void vApplicationStackOverflowHook( TaskHandle_t pxTask, char *pcTaskName );
_PERSISTENT uint8_t resetCount=0;
int main( void )
{
    /* CLK config. at 16MHz*/
    OSCILLATOR_Initialize();
    
    int buff[40];
    //initIO();

    // LCD test
    //LCDInit();
    //fprintf2(_LCD, "Hello LCD\n");
    
    // Uart1 test
    initUart1();
    if(_EXTR){
        sprintf(buff,"MCLR reset\n");
        resetCount=0;
        fprintf2(_UART1, buff);
    }
    else{
        sprintf(buff,"wdt resetting for the %dth times\n",++resetCount);
        fprintf2(_UART1, buff);
        if (resetCount >=7){
            fprintf2(_UART1,"sleeping ...\n"); 
            Sleep();
        }
    }
    _EXTR=0;
   /* Tasks creation */
    vStartTaskBlink1();
    vStartTaskBlink2();
     
	/* Finally start the scheduler. */
	vTaskStartScheduler();

	/* Will only reach here if there is insufficient heap available to start the scheduler. */
    while(1);
	return 0;
}
/*-----------------------------------------------------------*/


void vApplicationIdleHook( void )
{
        ClrWdt();
}

void vApplicationStackOverflowHook( TaskHandle_t pxTask, char *pcTaskName )
{
    pxTask= pxTask;
    pcTaskName = pcTaskName;
		for( ;; );
}
