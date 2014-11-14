/*
 * tsk_test.cpp
 *
 *  Created on: 31 mars 2014
 *      Author: Nico_user
 */

#include "tsk_rx.h"

/// === INCLUDES	================================================================================

//#include "serial.h"

/// === STATIC IMPORT	============================================================================

//xComPortHandle xSerialPort;

/// === PUBLIC DEFINITIONS	========================================================================

TSK_RX::TSK_RX()
		: Task("TSK_RX", 64, 1), timer("TIM_RX", 500, true, TSK_RX::callback)
{
}

/// ------------------------------------------------------------------------------------------------

void TSK_RX::run()
{
//	xSerialxPrintf_P(&xSerialPort, PSTR("Enter run\n"));

	static const TickType_t delay = 250;

	DDRB |= _BV(DDB4);
	DDRB |= _BV(DDB5);

	timer.start();

	for (;;)
	{
		bitSet(PORTB, PORTB4);
		OS::delayUntil(delay);

		bitClear(PORTB, PORTB4);
		OS::delayUntil(delay);
	}
}

void TSK_RX::callback(TimerHandle_t pxTimer)
{
	static bool b_on = true;

	if (b_on)
	{
		b_on = false;
		bitSet(PORTB, PORTB5);
	}
	else
	{
		b_on = true;
		bitClear(PORTB, PORTB5);
	}
}

/// === END OF FILE	================================================================================
