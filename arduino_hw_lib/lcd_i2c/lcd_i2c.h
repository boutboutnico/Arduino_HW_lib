///
/// lcd_I2C.h - Base class that provides basic function to drive a
/// textual LCD equipped with an I2C backpack
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
/// \file	lcd_i2c.h
/// \brief	Library for controlling LCD through I2C.
/// \date	05/04/2014
/// \author	nboutin
///

#ifndef LCD_I2C_H_
#define LCD_I2C_H_

/// ------------------------------------------------------------------------------------------------
/// INCLUDES
/// ------------------------------------------------------------------------------------------------
#include "Arduino.h"

///
/// The Streaming library must be included in order to use "operator<<"
/// It can be find at the following address: http://arduiniana.org/libraries/streaming/
/// I am not the author of it but it is a must-have.
///
#include "streaming.h"

/// ------------------------------------------------------------------------------------------------
/// NAMESPACE
/// ------------------------------------------------------------------------------------------------

namespace arduino_hw_lib
{

/// ------------------------------------------------------------------------------------------------
/// STRUCTURES
/// ------------------------------------------------------------------------------------------------
///
/// \namespace	arduino_hw_lib
/// \brief		Multiple Hardware libraries to be used with Arduino Boards.
/// \date		06/04/2014
///	\author		nboutin
///

///
/// \struct	_XY
/// \brief	Structure to used with operator<<, it allows to set the cursor at the desired position.
///
struct _XY
{
		const uint8_t x;
		const uint8_t y;
		_XY(const uint8_t x, const uint8_t y)
				: x(x), y(y)
		{
		}
};

/// ------------------------------------------------------------------------------------------------
/// CLASS
/// ------------------------------------------------------------------------------------------------

///
/// \class 	LCD_I2C
/// \brief	Manage LCD through I2C protocol.
/// \date	05/04/2014
/// \author	nboutin
///
class LCD_I2C : public Print, public Printable
{
	public:
		/// ----------------------------------------------------------------------------------------
		/// CONSTANTS
		/// ----------------------------------------------------------------------------------------

		static const uint8_t ROW_N_DEFAULT = 4;
		static const uint8_t COLUMN_N_DEFAULT = 20;
		static const uint8_t CURSOR_POSITON_DEFAULT = 0;

		static const uint8_t CLEAR_DELAY_MS = 15;
		static const uint8_t CURSOR_XY_DELAY_US = 100;

		/// ----------------------------------------------------------------------------------------
		/// PUBLIC DECLARATIONS
		/// ----------------------------------------------------------------------------------------

		LCD_I2C(const uint8_t i_ui8_lcd_address,
				const uint8_t i_ui8_nb_row = ROW_N_DEFAULT,
				const uint8_t i_ui8_nb_column = COLUMN_N_DEFAULT);

		virtual ~LCD_I2C();

		void begin();
		void clear();
		void backlight(const boolean i_b_on);
		void cursor(const boolean i_b_on);
		void home();
		void cursorXY(const uint8_t i_ui8_x, const uint8_t i_ui8_y);
		void moveToRow(const uint8_t i_ui8_y);
		void custom(const uint8_t i_ui8_code, const byte * i_byte_data);

		/// ----------------------------------------------------------------------------------------

		/// \see	Printable
		virtual size_t printTo(Print& p) const;

	protected:
		/// ----------------------------------------------------------------------------------------
		/// PROTECTED DECLARATIONS
		/// ----------------------------------------------------------------------------------------

		/// \see	Print
		virtual size_t write(uint8_t);

	private:
		/// ----------------------------------------------------------------------------------------
		/// PRIVATE ENUMERATIONS
		/// ----------------------------------------------------------------------------------------
		enum E8_LCD_Command
		{
			ROW_0 = 0x01,
			ROW_1 = 0x02,
			ROW_2 = 0x03,
			ROW_3 = 0x04,
			COMMAND = 0x1B,
			CLEAR = 0x43,
			BACKLIGHT_ON = 0x42,
			CUSTOM_CHAR = 0x44,
			HOME = 0x48,
			CURSOR_POS = 0x4C,
			CURSOR_ON = 0x53,
			BACKLIGHT_OFF = 0x62,
			CURSOR_OFF = 0x73
		};

		/// ----------------------------------------------------------------------------------------
		/// PRIVATE DECLARATIONS
		/// ----------------------------------------------------------------------------------------
		uint8_t nextRow();

		/// ----------------------------------------------------------------------------------------
		/// PRIVATE ATTRIBUTS
		/// ----------------------------------------------------------------------------------------

		const uint8_t ADDRESS;
		const uint8_t ROW_N_MAX;
		const uint8_t COLUMN_N_MAX;
		uint8_t ui8_current_row;
};

/// ------------------------------------------------------------------------------------------------
/// TEMPLATE SPECIALIZATION
/// ------------------------------------------------------------------------------------------------

///
/// \brief	Implement operator<< with the structure _XY to set the cursor
///			at the desired position before or after writing.
///	\code
///			LCD_I2C lcd;
///			lcd << _XY(10, 2);
///	\endcode
///
inline Print& operator<<(LCD_I2C& obj, const _XY& arg)
{
	obj.cursorXY(arg.x, arg.y);
	return obj;
}

}

#endif ///	LCD_I2C_H_
/// ------------------------------------------------------------------------------------------------
/// END OF FILE
/// ------------------------------------------------------------------------------------------------
