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
/// \file	encoder.cpp
/// \brief	Library to read encoder from a motor.
/// \date	08/04/2014
/// \author	nboutin
///

#include "encoder.h"
using namespace arduino_hw_lib;

/// ------------------------------------------------------------------------------------------------
/// INCLUDES
/// ------------------------------------------------------------------------------------------------

/// ------------------------------------------------------------------------------------------------
/// NAMESPACES
/// ------------------------------------------------------------------------------------------------
using namespace motor;

/// ------------------------------------------------------------------------------------------------
/// PUBLIC DEFINITIONS
/// ------------------------------------------------------------------------------------------------

Encoder::Encoder(	const uint8_t i_pin_A,
					const uint8_t i_int_pin_A,
					const uint8_t i_pin_B,
					const motor::E_Direction ie_direction)
		: 	pin_A(i_pin_A),
			int_pin_A(i_int_pin_A),
			pin_B(i_pin_B),
			e_direction(ie_direction),
			i32_cpt_encoder(0)
{
	begin();
}

int32_t Encoder::getCount() const
{
	if (e_direction == DIR_REVERSE)
	{
		return i32_cpt_encoder;
	}
	else
	{
		return -i32_cpt_encoder;
	}
}

/// ------------------------------------------------------------------------------------------------
/// PRIVATE DEFINITIONS
/// ------------------------------------------------------------------------------------------------

void Encoder::begin()
{
	pinMode(pin_A, INPUT);
	digitalWrite(pin_A, HIGH);    /// turn on pullup resistor

	pinMode(pin_B, INPUT);
	digitalWrite(pin_B, HIGH);    /// turn on pullup resistor

	attachInterruptWithArg(int_pin_A, wrapper_interrupt, this, CHANGE);
}

void Encoder::wrapper_interrupt(void* ip_arg)
{
	if (ip_arg != 0)
	{
		reinterpret_cast<Encoder*>(ip_arg)->update();
	}
}

void Encoder::update()
{
	/// found a low-to-high on channel A
	if (digitalRead(pin_A) == HIGH)
	{
		/// check channel B to see which way encoder is turning
		if (digitalRead(pin_B) == LOW)
		{
			i32_cpt_encoder--;         /// CCW
		}
		else
		{
			i32_cpt_encoder++;         /// CW
		}
	}
	/// found a high-to-low on channel A
	else
	{
		/// check channel B to see which way encoder is turning
		if (digitalRead(pin_B) == LOW)
		{
			i32_cpt_encoder++;          /// CW
		}
		else
		{
			i32_cpt_encoder--;          /// CCW
		}
	}
}

/// ------------------------------------------------------------------------------------------------
/// END OF FILE
/// ------------------------------------------------------------------------------------------------
