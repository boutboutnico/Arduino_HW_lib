///
/// srf05.cpp - Class that provides basic function to read value from
/// a SRF05 sensor.
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
/// \file	srf05.cpp
/// \brief	Library to read SRF05 sensor.
/// \date	07/04/2014
/// \author	nboutin
///

#include "srf05.h"
using namespace arduino_hw_lib;

/// ------------------------------------------------------------------------------------------------
/// INCLUDES
/// ------------------------------------------------------------------------------------------------

/// ------------------------------------------------------------------------------------------------
/// PUBLIC DEFINITIONS
/// ------------------------------------------------------------------------------------------------

SRF05::SRF05(	const uint8_t i_ui8_trigger_pin,
				const uint8_t i_ui8_echo_pin,
				const uint8_t i_ui8_min_cm,
				const uint16_t i_ui16_max_cm)
		: 	ui8_trigger_pin(i_ui8_trigger_pin),
			ui8_echo_pin(i_ui8_echo_pin),
			ui8_min_cm(i_ui8_min_cm),
			ui16_max_cm(i_ui16_max_cm)
{
	pinMode(ui8_trigger_pin, OUTPUT);
	pinMode(ui8_echo_pin, INPUT);

	digitalWrite(ui8_trigger_pin, LOW);
}

uint16_t SRF05::getDistance_cm() const
{
	delay(TYPICAL_RESPONSE_TIME_MS);

	digitalWrite(ui8_trigger_pin, HIGH);    /// send signal
	delayMicroseconds(TRIGGER_PULSE_DURATION_US);
	digitalWrite(ui8_trigger_pin, LOW);    /// close signal

	uint32_t ui32_pulse_time = pulseIn(ui8_echo_pin, HIGH, ECHO_PULSE_TIMEOUT_US);    /// calculate time for signal to return
	return constrain((ui32_pulse_time / TIME_US_TO_CM), ui8_min_cm, ui16_max_cm);    /// convert to centimeters
}

uint16_t SRF05::getDistanceAverage_cm()
{
	/// Shift old value to right
	for (uint8_t i = HISTORY_SIZE - 1; i > 0; i--)
	{
		tui16_average_distance[i] = tui16_average_distance[i - 1];
	}

	/// Store new value
	tui16_average_distance[0] = getDistance_cm();

	/// Average table
	uint16_t ui16_result = 0;
	for (uint8_t i = 0; i < HISTORY_SIZE; i++)
	{
		ui16_result += tui16_average_distance[i];
	}

	return ui16_result / HISTORY_SIZE;
}

/// ------------------------------------------------------------------------------------------------
/// PRIVATE DEFINITIONS
/// ------------------------------------------------------------------------------------------------

/// ------------------------------------------------------------------------------------------------
/// END OF FILE
/// ------------------------------------------------------------------------------------------------
