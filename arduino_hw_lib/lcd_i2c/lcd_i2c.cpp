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
/// \file	lcd_i2c.cpp
/// \brief	Library for controlling LCD through I2C.
/// \date	05/04/2014
/// \author	nboutin
///

#include "lcd_I2C.h"
using namespace arduino_hw_lib;

/// ------------------------------------------------------------------------------------------------
/// INCLUDES
/// ------------------------------------------------------------------------------------------------

#include "Wire.h"

/// ------------------------------------------------------------------------------------------------
/// Printable: PUBLIC INHERITED
/// ------------------------------------------------------------------------------------------------

size_t LCD_I2C::printTo(Print& p) const
{
	p << "Add:  " << ADDRESS << endl;
	p << "Size: " << COLUMN_N_MAX << " x " << ROW_N_MAX << endl;
	return 0;
}

/// ------------------------------------------------------------------------------------------------
/// Print: PROTECTED INHERITED
/// ------------------------------------------------------------------------------------------------

size_t LCD_I2C::write(uint8_t ui8_value)
{
	size_t n = 0;

	static uint8_t t[2] = { 0, 0 };
	t[0] = t[1];
	t[1] = ui8_value;

	/// Line Jump detected
	if (t[0] == '\r' && t[1] == '\n')
	{
		moveToRow(nextRow());
	}
	else if (ui8_value != '\r' && ui8_value != '\n')
	{
		Wire.beginTransmission(ADDRESS);
		n = Wire.write(ui8_value);
		Wire.endTransmission();
	}
	return n;
}

/// ------------------------------------------------------------------------------------------------
/// PUBLIC DEFINITIONS
/// ------------------------------------------------------------------------------------------------

LCD_I2C::LCD_I2C(	const uint8_t i_ui8_lcd_address,
					const uint8_t i_ui8_nb_row,
					const uint8_t i_ui8_nb_column)
		: 	ADDRESS(i_ui8_lcd_address),
			ROW_N_MAX(i_ui8_nb_row),
			COLUMN_N_MAX(i_ui8_nb_column),
			ui8_current_row(CURSOR_POSITON_DEFAULT)
{
	/// Nothing to do
}

LCD_I2C::~LCD_I2C()
{
	/// Nothing to do
}

void LCD_I2C::begin()
{
	Wire.begin(ADDRESS);
	clear();
}

void LCD_I2C::clear()
{
	ui8_current_row = CURSOR_POSITON_DEFAULT;

	Wire.beginTransmission(ADDRESS);
	Wire.write(COMMAND);
	Wire.write(CLEAR);
	Wire.endTransmission();
	delay(CLEAR_DELAY_MS);
}

void LCD_I2C::backlight(const boolean i_b_on)
{
	Wire.beginTransmission(ADDRESS);
	Wire.write(COMMAND);

	if (i_b_on) Wire.write(BACKLIGHT_ON);
	else Wire.write(BACKLIGHT_OFF);

	Wire.endTransmission();
}

void LCD_I2C::cursor(const boolean i_b_on)
{
	Wire.beginTransmission(ADDRESS);

	Wire.write(COMMAND);
	if (i_b_on) Wire.write(CURSOR_ON);
	else Wire.write(CURSOR_OFF);

	Wire.endTransmission();
}

void LCD_I2C::home()
{
	ui8_current_row = CURSOR_POSITON_DEFAULT;

	Wire.beginTransmission(ADDRESS);
	Wire.write(COMMAND);
	Wire.write(HOME);
	Wire.endTransmission();
}

void LCD_I2C::cursorXY(const uint8_t i_ui8_x, const uint8_t i_ui8_y)
{
	uint8_t x = i_ui8_x;
	uint8_t y = i_ui8_y;

	if (i_ui8_x > COLUMN_N_MAX - 1) x = 0;
	if (i_ui8_y > ROW_N_MAX - 1) y = 0;

	ui8_current_row = y;

	Wire.beginTransmission(ADDRESS);
	Wire.write(COMMAND);
	Wire.write(CURSOR_POS);
	Wire.write(x);
	Wire.write(y);
	Wire.endTransmission();
	delayMicroseconds(CURSOR_XY_DELAY_US);
}

void LCD_I2C::moveToRow(const uint8_t i_ui8_y)
{
	uint8_t y = i_ui8_y;

	if (i_ui8_y > ROW_N_MAX - 1) y = 0;

	ui8_current_row = y;

	Wire.beginTransmission(ADDRESS);
	switch (y)
	{
	case 0:
		Wire.write(ROW_0);
		break;
	case 1:
		Wire.write(ROW_1);
		break;
	case 2:
		Wire.write(ROW_2);
		break;
	case 3:
		Wire.write(ROW_3);
		break;
	default:
		Wire.write(ROW_0);
		break;
	}
	Wire.endTransmission();
}

void LCD_I2C::custom(const uint8_t i_ui8_code, const byte * i_byte_data)
{
	uint8_t code = i_ui8_code;

	if (i_ui8_code < 8 || i_ui8_code > 15) code = 8;

	Wire.beginTransmission(ADDRESS);
	Wire.write(COMMAND);
	Wire.write(CUSTOM_CHAR);
	Wire.write(code);
	Wire.write(i_byte_data, 8);
	Wire.endTransmission();
}

/// ------------------------------------------------------------------------------------------------
/// PRIVATE DEFINITIONS
/// ------------------------------------------------------------------------------------------------

uint8_t LCD_I2C::nextRow()
{
	if (++ui8_current_row > (ROW_N_MAX - 1))
	{
		ui8_current_row = CURSOR_POSITON_DEFAULT;
	}

	return ui8_current_row;
}

/// ------------------------------------------------------------------------------------------------
/// END OF FILE
/// ------------------------------------------------------------------------------------------------
