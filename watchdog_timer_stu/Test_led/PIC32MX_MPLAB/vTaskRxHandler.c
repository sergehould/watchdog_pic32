/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "include/console32.h"
#include "include/public.h" 
//#include "include/adc.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define     CUR_LIMIT   205
#define     STEP_SPEED  2

extern volatile char debug;

/* Private static data declarations */
static unsigned int dc=75;
static unsigned int speed=0;

/* Private static mutex, semaphore and queue declarations*/
static xSemaphoreHandle mutDispl;
static xSemaphoreHandle mutDC;
static xSemaphoreHandle mutSpeed;
static QueueHandle_t xQueueCtl = NULL;

/* Private static function declarations */
static void vTaskCtl( void *pvParameters );


     
void vStartTaskRxHandler(void){
     mutSpeed = xSemaphoreCreateMutex();
    xQueueCtl = xQueueCreate( 15, sizeof( char ) );
    mutDispl = xSemaphoreCreateMutex();
    mutDC = xSemaphoreCreateMutex();
    xTaskCreate( vTaskCtl, ( char * ) "TCtl", 240, NULL, 2, NULL );

} 

/* This task is the control and central task */
static void vTaskCtl( void *pvParameters )
{
    pvParameters =pvParameters ;
    char buff2[10] ;
    char buff_p[50];
	char buff[10];
    volatile unsigned long debug=0;
    char rx=0, temp;
//    xMessToSend xMess= {0,0};
    static int i=0;
	// Initializes the system's variables
    static unsigned int cur=0, curSet=CUR_LIMIT,tempSet=75,speedSet= 800,  cnt=0, cnt2=0;
    
    portBASE_TYPE xStatus;    
  //  printMenu();
	/* As per most tasks, this task is implemented in an infinite loop. */
	for( ;; )
	{

        
        //xQueueSendToBack(xQueueLCD,&xMess,0);				// Sends to vTaskLCD()
		
		/* The following queues are partially blocking.  Each queue wait 100mS before unblocking */
        xQueueReceive( xQueueCtl, &rx, portMAX_DELAY );
       // xStatus3=xQueueReceive( xQueueCtl3, &rx3, (100/portTICK_RATE_MS));		// From T2
        //xStatus=xQueueReceive( xQueueCtl, &rx, (100/portTICK_RATE_MS));			// From BTNtask and Rx task
        //xStatus2=xQueueReceive( xQueueCtl2, &rx2, (100/portTICK_RATE_MS));	// From vTaskConvSpeed
        temp =rx;
        sprintf(buff,"%c",rx);
        fprintf2(C_UART2, buff); // 
    }
        
}


void vSendQueueCtlFromISR(char cChar){

    xQueueSendFromISR( xQueueCtl, &cChar, 0 );
}


