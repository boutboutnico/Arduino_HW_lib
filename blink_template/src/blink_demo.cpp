///
/// This example code is in the public domain.
/// \file	blink_demo.cpp
/// \brief	Template Arduino project for eclipse.
/// \date	07/04/2014
/// \author	nboutin
///
///

/// ------------------------------------------------------------------------------------------------
/// INCLUDES
/// ------------------------------------------------------------------------------------------------
#include "Arduino.h"

/// ------------------------------------------------------------------------------------------------
/// NAMESPACE
/// ------------------------------------------------------------------------------------------------

/// ------------------------------------------------------------------------------------------------
/// GLOBALE VARIABLES
/// ------------------------------------------------------------------------------------------------
static const uint8_t led_pin = 13;

/// ------------------------------------------------------------------------------------------------
/// SETUP
/// ------------------------------------------------------------------------------------------------

void setup(void)
{
	pinMode(led_pin, OUTPUT);
}

/// ------------------------------------------------------------------------------------------------
/// LOOP
/// ------------------------------------------------------------------------------------------------

void loop(void)
{
	const uint16_t ui16_delay = 500;
	static boolean led_status = LOW;

	led_status = ~led_status;

	digitalWrite(led_pin, led_status);
	delay(ui16_delay);

}

/// ------------------------------------------------------------------------------------------------
/// END OF FILE
/// ------------------------------------------------------------------------------------------------