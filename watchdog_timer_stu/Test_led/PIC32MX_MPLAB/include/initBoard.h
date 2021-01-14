/***********************************************************************************************
*
*
* FileName:  initBoard.H      
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author        	Date            Version     Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Serge Hould      14 Jan. 2021		v1.0.0      Setup for PIC32    
* 
*
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

#ifndef INITBOARD_H
#define INITBOARD_H
/**
    Section: Includes
*/
#include <stdint.h>
#include <xc.h>
#include "FreeRTOS.h"
/* Hardware specific includes. */
#include "ConfigPerformance.h"
/**
    Section: Macros
*/
//macros definitions
/**
    Section: Function Prototypes
*/
#define SYS_FREQ 80000000 // Running at 80MHz
void initIO(void);
void prvSetupHardware( void );

#endif
