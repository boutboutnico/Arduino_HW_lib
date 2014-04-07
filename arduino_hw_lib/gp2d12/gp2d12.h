///
/// gp2d12.h - Class that provides basic function to read value from
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
/// \file	gp2d12.h
/// \brief	Library to read GP2D12 sensor.
/// \date	07/04/2014
/// \author	nboutin
///

#ifndef GP2D12_H_
#define GP2D12_H_

/// FEATURES
/// • Analog output
/// • Effective Range: 10 to 80 cm
/// • LED pulse cycle duration: 32 ms
/// • Typical response time: 39 ms
/// • Typical start up delay: 44 ms
/// • Average current consumption: 33 mA
/// • Detection area diameter @ 80 cm: 6 cm
/// DESCRIPTION
/// The GP2D12 is a distance measuring sensor with
/// integrated signal processing and analog voltage output.

/// ------------------------------------------------------------------------------------------------
/// INCLUDES
/// ------------------------------------------------------------------------------------------------
#include "Arduino.h"

/// ------------------------------------------------------------------------------------------------
/// NAMESPACE
/// ------------------------------------------------------------------------------------------------

namespace arduino_hw_lib
{

/// ------------------------------------------------------------------------------------------------
/// CLASS
/// ------------------------------------------------------------------------------------------------

///
/// \class 	GP2D12
/// \brief	Class to read GP2D12 sensor.
/// \date	07/04/2014
/// \author	nboutin
///
class GP2D12
{
	public:
		/// ----------------------------------------------------------------------------------------
		/// CONSTANTS
		/// ----------------------------------------------------------------------------------------

		/// Typical response time: 39 ms
		static const uint8_t TYPICAL_RESPONSE_TIME_MS = 39;

		/// Typical start up delay: 44 ms
		static const uint8_t TYPICAL_START_UP_DELAY_MS = 44;

		static const uint8_t DISTANCE_MIN_DEFAULT = 10;
		static const uint8_t DISTANCE_MAX_DEFAULT = 80;
		static const uint8_t HISTORY_SIZE = 5;

		/// ----------------------------------------------------------------------------------------
		/// PUBLIC DECLARATIONS
		/// ----------------------------------------------------------------------------------------

		GP2D12(	const uint8_t i_ui8_input_pin,
				const uint8_t i_ui8_min_cm = DISTANCE_MIN_DEFAULT,
				const uint8_t i_ui8_max_cm = DISTANCE_MAX_DEFAULT);

		uint16_t getTension();
		uint8_t getDistance_cm();
		uint8_t getDistanceAverage_cm();

	private:
		/// ----------------------------------------------------------------------------------------
		/// PRIVATE ATTRIBUTS
		/// ----------------------------------------------------------------------------------------

		const uint8_t ui8_input_pin;
		const uint8_t ui8_min_cm;
		const uint8_t ui8_max_cm;

		uint8_t tui8_average_distance[HISTORY_SIZE];
};

}
#endif ///	GP2D12_H_
/// ------------------------------------------------------------------------------------------------
/// END OF FILE
/// ------------------------------------------------------------------------------------------------
