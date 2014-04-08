///
/// Class that provides basic function to read encoder from a motor.
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
/// \file	encoder.h
/// \brief	Library to read encoder from a motor.
/// \date	08/04/2014
/// \author	nboutin
///

#ifndef ENCODER_H_
#define ENCODER_H_

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

///	\typedef	T_pfunc_it
///	\brief		Pointer to function for interrupt.
typedef void (*T_pfunc_it)(void);

/// ------------------------------------------------------------------------------------------------
/// CLASS
/// ------------------------------------------------------------------------------------------------

///
/// \class 	Encoder
/// \brief	Class to read encoder from a motor.
/// \date	08/04/2014
/// \author	nboutin
///
class Encoder
{
	public:
		/// ----------------------------------------------------------------------------------------
		/// PUBLIC DECLARATIONS
		/// ----------------------------------------------------------------------------------------

		Encoder(const uint8_t i_pin_A,
				const uint8_t i_int_pin_A,
				const uint8_t i_pin_B,
				const T_pfunc_it& ipf_interrupt,
				const motor::E_Direction ie_direction);

		void update();
		int32_t getCount() const;

	private:
		/// ----------------------------------------------------------------------------------------
		/// PRIVATE DECLARATIONS
		/// ----------------------------------------------------------------------------------------

		void begin(const T_pfunc_it& ipf_interrupt);

		/// ----------------------------------------------------------------------------------------
		/// PRIVATE ATTRIBUTS
		/// ----------------------------------------------------------------------------------------

		const uint8_t pin_A;
		const uint8_t int_pin_A;
		const uint8_t pin_B;
		const motor::E_Direction e_direction;

		int32_t i32_cpt_encoder;
};

}

#endif	/// ENCODER_H_
/// ------------------------------------------------------------------------------------------------
/// END OF FILE
/// ------------------------------------------------------------------------------------------------
