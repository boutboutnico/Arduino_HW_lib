///
/// Class that provides basic function to drive a motor.
/// Copyright (c) 2013 Nicolas BOUTIN.  All right reserved.
///
/// This library is free software; you can redistribute it and/or
/// modify it under the terms of the GNU Lesser General Public
/// License as published by the Free Software Foundation; either
/// version 2.1 of the License, or (at your option) any later version.
///
/// This library is distributed in the hope that it will be useful,
/// but WITHOUT ANY WARRANTY; without even the implied warranty of
/// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
/// Lesser General Public License for more details.
///
/// You should have received a copy of the GNU Lesser General Public
/// License along with this library; if not, write to the Free Software
/// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
/// ------------------------------------------------------------------------------------------------
///
/// \file	motor.cpp
/// \brief	Library to drive motor.
/// \date	08/04/2014
/// \author	nboutin
///

#include "motor.h"
using namespace arduino_hw_lib;

/// ------------------------------------------------------------------------------------------------
/// INCLUDES
/// ------------------------------------------------------------------------------------------------

/// ------------------------------------------------------------------------------------------------
/// PUBLIC DEFINITIONS
/// ------------------------------------------------------------------------------------------------

Motor::Motor(const uint8_t i_ui8_dir_pin, const uint8_t i_ui8_cmd_pin, const boolean i_b_dir)
		: 	ui8_dir_pin(i_ui8_dir_pin),
			ui8_cmd_pin(i_ui8_cmd_pin),
			b_dir(i_b_dir),
			b_current_dir(i_b_dir)
{
	/// Nothing to do
	begin();
}

void Motor::command(const int16_t i_i16_command)
{
	/// Change direction only when needed
	switch (b_dir)
	{
	case FORWARD:
		if (i_i16_command < 0 && b_current_dir != REVERSE)
		{
			b_current_dir = REVERSE;
			digitalWrite(ui8_dir_pin, b_current_dir);

#ifdef __DBG_MOT
			Serial.print("Change dir 1 :");
			Serial.println(b_current_dir);
#endif
		}
		else if (i_i16_command >= 0 && b_current_dir != FORWARD)
		{
			b_current_dir = FORWARD;
			digitalWrite(ui8_dir_pin, b_current_dir);

#ifdef __DBG_MOT
			Serial.print("Change dir 2 :");
			Serial.println(b_current_dir);
#endif
		}
		break;

	case REVERSE:
		if (i_i16_command < 0 && b_current_dir != FORWARD)
		{
			b_current_dir = FORWARD;
			digitalWrite(ui8_dir_pin, b_current_dir);

#ifdef __DBG_MOT
			Serial.print("Change dir 3 :");
			Serial.println(b_current_dir);
#endif
		}
		else if (i_i16_command >= 0 && b_current_dir != REVERSE)
		{
			b_current_dir = REVERSE;
			digitalWrite(ui8_dir_pin, b_current_dir);

#ifdef __DBG_MOT
			Serial.print("Change dir 4 :");
			Serial.println(b_current_dir);
#endif
		}
		break;
	}

	/// Apply command
	/// Forward
	if (i_i16_command >= 0)
	{
		analogWrite(ui8_cmd_pin, i_i16_command);
	}
	/// Backward
	else
	{
		analogWrite(ui8_cmd_pin, abs(i_i16_command));
	}

#ifdef __DBG_MOT
	Serial.print("cmd ");
	Serial.println(i_i16_command);
#endif
}

/// ------------------------------------------------------------------------------------------------
/// PRIVATE DEFINITIONS
/// ------------------------------------------------------------------------------------------------

void Motor::begin()
{
	pinMode(ui8_dir_pin, OUTPUT);
	pinMode(ui8_cmd_pin, OUTPUT);
	digitalWrite(ui8_dir_pin, b_dir);
	analogWrite(ui8_cmd_pin, COMMAND_DEFAULT);
}

/// ------------------------------------------------------------------------------------------------
/// END OF FILE
/// ------------------------------------------------------------------------------------------------
