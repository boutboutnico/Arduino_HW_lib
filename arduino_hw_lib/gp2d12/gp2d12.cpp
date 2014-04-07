///
/// gp2d12.cpp - Class that provides basic function to read value from
/// a GP2D12 sensor.
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
/// \file	gp2d12.cpp
/// \brief	Library to read GP2D12 sensor.
/// \date	07/04/2014
/// \author	nboutin
///

#include "gp2d12.h"
using namespace arduino_hw_lib;

/// ------------------------------------------------------------------------------------------------
/// INCLUDES
/// ------------------------------------------------------------------------------------------------

/// ------------------------------------------------------------------------------------------------
/// PUBLIC DEFINITIONS
/// ------------------------------------------------------------------------------------------------

GP2D12::GP2D12(	const uint8_t i_ui8_input_pin,
				const uint8_t i_ui8_min_cm,
				const uint8_t i_ui8_max_cm)
		: ui8_input_pin(i_ui8_input_pin), ui8_min_cm(i_ui8_min_cm), ui8_max_cm(i_ui8_max_cm)
{
	pinMode(ui8_input_pin, INPUT);
//	delay(TYPICAL_START_UP_DELAY_MS);
}

uint16_t GP2D12::getTension()
{
	delay(TYPICAL_RESPONSE_TIME_MS);
	return analogRead(ui8_input_pin);
}

uint8_t GP2D12::getDistance_cm()
{
	uint16_t tension = getTension();
	uint8_t distance = (6787.0 / ((float) tension - 3.0)) - 4.0;
	return constrain(distance, ui8_min_cm, ui8_max_cm);
}

uint8_t GP2D12::getDistanceAverage_cm()
{
	/// Shift old value to right
	for (uint8_t i = HISTORY_SIZE - 1; i > 0; i--)
	{
		tui8_average_distance[i] = tui8_average_distance[i - 1];
	}

	/// Store new value
	tui8_average_distance[0] = getDistance_cm();

	/// Average table
	uint16_t ui16_result = 0;
	for (uint8_t ui8_idx = 0; ui8_idx < HISTORY_SIZE; ui8_idx++)
	{
		ui16_result += tui8_average_distance[ui8_idx];
	}

	return ui16_result / HISTORY_SIZE;
}

/// ------------------------------------------------------------------------------------------------
/// PRIVATE DEFINITIONS
/// ------------------------------------------------------------------------------------------------

/// ------------------------------------------------------------------------------------------------
/// END OF FILE
/// ------------------------------------------------------------------------------------------------
