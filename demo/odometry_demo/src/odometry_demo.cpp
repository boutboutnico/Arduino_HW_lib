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
#include "odometry.h"

/// ------------------------------------------------------------------------------------------------
/// NAMESPACE
/// ------------------------------------------------------------------------------------------------
using namespace arduino_hw_lib;
using namespace motor;

/// ------------------------------------------------------------------------------------------------
/// GLOBALE VARIABLES
/// ------------------------------------------------------------------------------------------------

/// dir_pin / cmd_pin / dir
Motor r_mot(4, 5, DIR_FORWARD);
Motor l_mot(7, 6, DIR_REVERSE);

/// pin_A / int_pin_A / pin_B / int_func / is_CCW
Encoder r_enc(3, 1, 9, DIR_FORWARD);
Encoder l_enc(2, 0, 8, DIR_REVERSE);

static const float WHEEL_BASE = 27.75;    /// mm
static const float LEFT_CLICKS_PER_CM = 14.40;
static const float RIGHT_CLICKS_PER_CM = 14.30;

Odometry odo(WHEEL_BASE, LEFT_CLICKS_PER_CM, RIGHT_CLICKS_PER_CM);

/// ------------------------------------------------------------------------------------------------
/// SETUP
/// ------------------------------------------------------------------------------------------------

static const uint16_t ui16_cmd = 0;

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
	static const uint16_t ui16_delay = 250;

	odo.compute(l_enc.getCount(), r_enc.getCount());

	Serial << "--------------------" << endl;
	Serial << "l_enc: \t" << l_enc.getCount() << endl;
	Serial << "r_enc: \t" << r_enc.getCount() << endl;

	delay(ui16_delay);
}

/// ------------------------------------------------------------------------------------------------
/// END OF FILE
/// ------------------------------------------------------------------------------------------------
