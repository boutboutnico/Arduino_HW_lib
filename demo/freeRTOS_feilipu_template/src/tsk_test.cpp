/*
 * tsk_test.cpp
 *
 *  Created on: 31 mars 2014
 *      Author: Nico_user
 */

#include "tsk_test.h"

/// === INCLUDES	================================================================================

#include "serial.h"
#include "Arduino.h"

/// === STATIC IMPORT	============================================================================

xComPortHandle xSerialPort;

/// === STATIC DEFINITIONS	========================================================================

OS::Semaphore TSK_T1::sem(TSK_T1::SEMAPHORE_N_TOKEN);

/// === PUBLIC DEFINITIONS	========================================================================

TSK_T1::TSK_T1()
		: 	Task("TSK_T1", STACK_SIZE, STACK_PRIORITY),
			timer("TIM1", TIMER_DURATION, true, TSK_T1::callback)
{

}

/// ------------------------------------------------------------------------------------------------

void TSK_T1::run()
{
	xSerialxPrintf_P(&xSerialPort, PSTR("Enter run\n"));

//	static const TickType_t delay = 1000;

	bitSet(DDRB, DDB4);
	bitClear(PORTB, PORTB4);

	timer.start();

	for (;;)
	{
		sem.take(SEMAPHORE_TIMEOUT);
		bitSet(PORTB, PORTB4);

		sem.take(SEMAPHORE_TIMEOUT);
		bitClear(PORTB, PORTB4);

//		bitClear(PORTB, PORTB4);
//		OS::delayUntil(delay);
//
//		bitSet(PORTB, PORTB4);
//		OS::delayUntil(delay);

//		xSerialxPrintf_P(&xSerialPort, PSTR("Current Timestamp: %lu xTaskGetTickCount(): %u\r\n"),
//				time(NULL), xTaskGetTickCount());
	}
}

/// ------------------------------------------------------------------------------------------------

void TSK_T1::callback(TimerHandle_t pxTimer)
{
	sem.give();
}

/// ------------------------------------------------------------------------------------------------

void TSK_Test1::run()
{
	xSerialxPrintf_P(&xSerialPort, PSTR("Enter run1\n"));

	TickType_t xLastWakeTime;
	xLastWakeTime = xTaskGetTickCount();

	const TickType_t xFrequency = (1000 / portTICK_PERIOD_MS);

	DDRB |= _BV(DDB4);

	for (;;)
	{
		PORTB |= _BV(PORTB4);
		vTaskDelayUntil(&xLastWakeTime, xFrequency);

		PORTB &= ~_BV(PORTB4);
		vTaskDelayUntil(&xLastWakeTime, xFrequency);

//		xSerialxPrintf_P(&xSerialPort, PSTR("Current Timestamp: %lu xTaskGetTickCount(): %u\r\n"),
//				time(NULL), xTaskGetTickCount());
	}
}

