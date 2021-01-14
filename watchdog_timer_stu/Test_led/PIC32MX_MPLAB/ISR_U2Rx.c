/* Scheduler includes. */
#include "FreeRTOS.h"
#include "queue.h"
#include "semphr.h"
#include "include/console32.h"
#include "include/public.h"

//void __ISR( _UART_2_VECTOR, IPL1SOFT) U2RXInterrupt( void){
//    static int rx=0;
//    char buff[2];
//    // clear interrupt flag
//    mU2RXClearIntFlag();
//    rx=U2RXREG;
//    sprintf(buff,"%c",rx);
//    fprintf2(C_UART2, buff); // 
//}
void __ISR( _UART_2_VECTOR, IPL1SOFT) U2RXInterrupt( void){
    char cChar;
   // static char i=0;
  //  portBASE_TYPE xHigherPriorityTaskWoken = pdFALSE;

	/* Get the character and post it on the queue of Rxed characters.
	If the post causes a task to wake force a context switch as the woken task
	may have a higher priority than the task we have interrupted. */
	mU2RXClearIntFlag();
    //IFS1bits.U2RXIF = 0;
	while( U2STAbits.URXDA )
	{
		cChar = U2RXREG;
     //   buff[i++]=cChar;
		//xQueueSendFromISR( xQueueCtl, &cChar, &xHigherPriorityTaskWoken );
        vSendQueueCtlFromISR(cChar);
       // xQueueSendFromISR( xQueueCtl, &cChar, 0 );
	}
/*
	if( xHigherPriorityTaskWoken != pdFALSE )
	{
		taskYIELD();
        debug++;
	}
 */
}
 