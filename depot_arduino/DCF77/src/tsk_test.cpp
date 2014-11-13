/*
 * tsk_test.cpp
 *
 *  Created on: 31 mars 2014
 *      Author: Nico_user
 */

#include "tsk_test.h"
#include "serial.h"

//const int8_t TSK_Test::name [] = "TSK_Test";
//const int8_t TSK_Test1::name [] = "TSK_Test1";

xComPortHandle xSerialPort;

void TSK_Test::run()
{
	xSerialxPrintf_P(&xSerialPort, PSTR("Enter run\n"));

	TickType_t xLastWakeTime;
	xLastWakeTime = xTaskGetTickCount();

	const TickType_t xFrequency = (500 / portTICK_PERIOD_MS);

	DDRB |= _BV(DDB5);

	for (;;)
	{
		PORTB |= _BV(PORTB5);
		vTaskDelayUntil(&xLastWakeTime, xFrequency);

		PORTB &= ~_BV(PORTB5);
		vTaskDelayUntil(&xLastWakeTime, xFrequency);

//		xSerialxPrintf_P(&xSerialPort, PSTR("Current Timestamp: %lu xTaskGetTickCount(): %u\r\n"),
//				time(NULL), xTaskGetTickCount());
	}
}

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

