/***************************************************************************** 
 * Author   Date            Version     Comment
 * SH       13 Jan 2021     1.0         Watchdog timer tested OK
 * 
 *     TO COMPLETE BY THE STUDENT
 *****************************************************************************/


/* peripheral library include */
#include <plib.h>
#include <stdio.h>
//#include <stdlib.h>
/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h" 
#include "semphr.h"
#include "croutine.h"
/* Hardware specific includes. */
#include "ConfigPerformance.h"

#include "include/console32.h"
#include "include/initBoard.h"
#include "include/public.h"


/* Prototypes for the standard FreeRTOS callback/hook functions implemented within this file. */
void vApplicationStackOverflowHook( TaskHandle_t pxTask, char *pcTaskName );


int main( void ){

    /* Prepare the hardware */
	prvSetupHardware();
    initIO();
    LCDInit();
    initUart1();
    
    /* CONSOLE is defined inside public.h */
    fprintf2(CONSOLE, "Hello\n");
    
     
    /* Tasks creation */
        
	/* Start the tasks and timer running. */
    vTaskStartScheduler();
	
	

	return 0;
}
/*-----------------------------------------------------------*/

/* vApplicationIdleHook runs only when no task requires the CPU */
void vApplicationIdleHook( void ){

    while(1){
        // your code here
    }
}

/* vApplicationStackOverflowHook */
void vApplicationStackOverflowHook( TaskHandle_t pxTask, char *pcTaskName )
{
    pxTask= pxTask;
    pcTaskName = pcTaskName;
		for( ;; );
}