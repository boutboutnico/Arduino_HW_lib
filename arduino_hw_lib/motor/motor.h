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
/// \file	motor.h
/// \brief	Library to drive motor.
/// \date	08/04/2014
/// \author	nboutin
///

#ifndef MOTOR_H_
#define MOTOR_H_

/// ------------------------------------------------------------------------------------------------
/// INCLUDES
/// ------------------------------------------------------------------------------------------------
#include "Arduino.h"

#include "motor_typedef.h"

/// ------------------------------------------------------------------------------------------------
/// NAMESPACE
/// ------------------------------------------------------------------------------------------------

namespace arduino_hw_lib
{

/// ------------------------------------------------------------------------------------------------
/// CLASS
/// ------------------------------------------------------------------------------------------------

///
/// \class 	Motor
/// \brief	Class to drive motor.
/// \date	08/04/2014
/// \author	nboutin
///
class Motor
{
	public:
		/// ----------------------------------------------------------------------------------------
		/// CONSTANTS
		/// ----------------------------------------------------------------------------------------

		static const uint8_t COMMAND_DEFAULT = 0;

		/// ----------------------------------------------------------------------------------------
		/// PUBLIC DECLARATIONS
		/// ----------------------------------------------------------------------------------------

		Motor(	const uint8_t i_ui8_dir_pin,
				const uint8_t i_ui8_cmd_pin,
				const motor::E_Direction ie_direction);

		void command(const int16_t i_i16_command);

	private:
		/// ----------------------------------------------------------------------------------------
		/// PRIVATE DECLARATIONS
		/// ----------------------------------------------------------------------------------------

		void begin();

		/// ----------------------------------------------------------------------------------------
		/// PRIVATE ATTRIBUTS
		/// ----------------------------------------------------------------------------------------

		const uint8_t ui8_dir_pin;
		const uint8_t ui8_cmd_pin;
		const motor::E_Direction e_direction;

		motor::E_Direction e_current_direction;
};

}

#endif	/// MOTOR_H_
/// ------------------------------------------------------------------------------------------------
/// END OF FILE
/// ------------------------------------------------------------------------------------------------
