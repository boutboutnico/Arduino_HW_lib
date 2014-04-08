///
/// This example code is in the public domain.
/// \file	motor_demo.cpp
/// \brief	Demonstrates use of the Motor Library.
/// \date	08/04/2014
/// \author	nboutin
///

/// ------------------------------------------------------------------------------------------------
/// INCLUDES
/// ------------------------------------------------------------------------------------------------
#include "Arduino.h"

#include "streaming.h"
#include "motor.h"
#include "encoder.h"

/// ------------------------------------------------------------------------------------------------
/// NAMESPACE
/// ------------------------------------------------------------------------------------------------
using namespace arduino_hw_lib;

/// ------------------------------------------------------------------------------------------------
/// GLOBALE VARIABLES
/// ------------------------------------------------------------------------------------------------

/// dir_pin / cmd_pin / dir
Motor r_mot(4, 5, Motor::FORWARD);
Motor l_mot(7, 6, Motor::REVERSE);

/// pin_A / int_pin_A / pin_B / int_func / is_CCW
void doRightEncoder();
void doLeftEncoder();

Encoder r_enc(3, 1, 9, doRightEncoder, true);
Encoder l_enc(2, 0, 8, doLeftEncoder, false);

/// ------------------------------------------------------------------------------------------------
/// SETUP
/// ------------------------------------------------------------------------------------------------

static const uint16_t ui16_cmd = 100;

void setup(void)
{
	Serial.begin(9600);

	l_mot.command(ui16_cmd);
	r_mot.command(ui16_cmd);
}

/// ------------------------------------------------------------------------------------------------
/// LOOP
/// ------------------------------------------------------------------------------------------------

void loop(void)
{
	static const uint16_t ui16_delay = 500;

	Serial << "--------------------" << endl;
	Serial << "l_enc: \t" << l_enc.getCount() << endl;
	Serial << "r_enc: \t" << r_enc.getCount() << endl;

	static uint8_t cpt = 0;
	if (cpt++ == 6)
	{
		l_mot.command(-ui16_cmd);
		r_mot.command(-ui16_cmd);
	}

	if (cpt > 12)
	{
		l_mot.command(0);
		r_mot.command(0);
	}

	delay(ui16_delay);
}

/// ------------------------------------------------------------------------------------------------
/// INTERRUPT
/// ------------------------------------------------------------------------------------------------

void doRightEncoder()
{
	r_enc.update();
}

void doLeftEncoder()
{
	l_enc.update();
}

/// ------------------------------------------------------------------------------------------------
/// END OF FILE
/// ------------------------------------------------------------------------------------------------
