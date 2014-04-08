///
/// srf05.h - Class that provides basic function to read value from
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
/// \file	srf05.h
/// \brief	Library to read SRF05 sensor.
/// \date	07/04/2014
/// \author	nboutin
///

#ifndef SRF05_H_
#define SRF05_H_

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
/// \class 	SRF05
/// \brief	Class to read SRF05 sensor.
/// \date	07/04/2014
/// \author	nboutin
///
class SRF05
{
		SRF05(const SRF05& m);    /// Disabled
		SRF05& operator=(const SRF05& m);    /// Disabled
	public:
		/// ----------------------------------------------------------------------------------------
		/// CONSTANTS
		/// ----------------------------------------------------------------------------------------
		static const uint8_t DISTANCE_MIN_DEFAULT = 1;
		static const uint16_t DISTANCE_MAX_DEFAULT = 300;
		static const uint8_t TYPICAL_RESPONSE_TIME_MS = 50;

		static const uint8_t TIME_US_TO_CM = 58;	/// Conversion coefficient
		static const uint8_t TRIGGER_PULSE_DURATION_US = 20;    /// (µs) >= 10µs minimum.
		static const uint32_t ECHO_PULSE_TIMEOUT_US = 300000;    /// (µs) if no object detected.

		static const uint8_t HISTORY_SIZE = 5;

		/// ----------------------------------------------------------------------------------------
		/// PUBLIC DECLARATIONS
		/// ----------------------------------------------------------------------------------------

		SRF05(	const uint8_t i_ui8_trigger_pin,
				const uint8_t i_ui8_echo_pin,
				const uint8_t i_ui8_min_cm = DISTANCE_MIN_DEFAULT,
				const uint16_t i_ui16_max_cm = DISTANCE_MAX_DEFAULT);

		uint16_t getDistance_cm() const;

		uint16_t getDistanceAverage_cm();

	private:
		/// ----------------------------------------------------------------------------------------
		/// PRIVATE ATTRIBUTS
		/// ----------------------------------------------------------------------------------------
		const uint8_t ui8_trigger_pin;
		const uint8_t ui8_echo_pin;

		const uint8_t ui8_min_cm;
		const uint16_t ui16_max_cm;

		uint16_t tui16_average_distance[HISTORY_SIZE];
};

}

#endif	/// SRF05_H_
/// ------------------------------------------------------------------------------------------------
/// END OF FILE
/// ------------------------------------------------------------------------------------------------
