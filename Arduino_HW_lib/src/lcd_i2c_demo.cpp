///
/// This example code is in the public domain.
/// \file	lcd_i2c_demo.cpp
/// \brief	Demonstrates use of the LCD Library
/// \date	05/04/2014
/// \author	nboutin
///
/// Board	Arduino UNO R3
/// IDE		Eclipse Kepler
/// LCD I2C	PCM2004E6-2
/// Pin		Board	LCD
/// SDA_20	SDA 	(white) + resistance pull-up 2k
/// SCL_21	SCL 	(yellow) + resistance pull-up 2k
/// 5V		5V 		(red)
/// GND		GND		(black)
///

/// ------------------------------------------------------------------------------------------------
/// INCLUDES
/// ------------------------------------------------------------------------------------------------
#include "Arduino.h"

#include "lcd_i2c.h"

/// ------------------------------------------------------------------------------------------------
/// NAMESPACE
/// ------------------------------------------------------------------------------------------------
using namespace arduino_hw_lib;

/// ------------------------------------------------------------------------------------------------
/// GLOBALE VARIABLES
/// ------------------------------------------------------------------------------------------------
LCD_I2C lcd(0x00, 4, 20);

#define LCD_BASIC_FUNC
#define LCD_PRINT

/// ------------------------------------------------------------------------------------------------
/// SETUP
/// ------------------------------------------------------------------------------------------------

void setup(void)
{
	Serial.begin(9600);
	lcd.begin();
}

/// ------------------------------------------------------------------------------------------------
/// LOOP
/// ------------------------------------------------------------------------------------------------

void loop(void)
{
	static const uint32_t ui32_lcd_delay = 3000;

//	Serial << "boolean:\t" << sizeof(boolean) << endl;    /// 1
//	Serial << "uint8_t:\t" << sizeof(uint8_t) << endl;    /// 1
//	Serial << "uint16_t:\t" << sizeof(uint16_t) << endl;    /// 2
//	Serial << "uint32_t:\t" << sizeof(uint32_t) << endl;    /// 4

	lcd.clear();
	lcd << "-- LCD Demo start --" << endl;
	delay(ui32_lcd_delay);

#ifdef LCD_BASIC_FUNC
	lcd.clear();
	lcd << "-- Backlight OFF --" << endl;
	lcd.backlight(false);
	delay(ui32_lcd_delay);

	lcd.clear();
	lcd << "-- Backlight ON --" << endl;
	lcd.backlight(true);
	delay(ui32_lcd_delay);

	lcd.clear();
	lcd << "-- CursorXY (5,3) --" << endl;
	lcd.cursorXY(5, 3);
	lcd << 'X';
	delay(ui32_lcd_delay);

	lcd.clear();
	lcd << "- CursorXY (10,2) -" << endl;
	lcd << _XY(10, 2) << 'X';
	delay(ui32_lcd_delay);

	lcd.clear();
	lcd.print("-- Cursor OFF --");
	lcd.cursor(false);
	delay(ui32_lcd_delay);

	lcd.clear();
	lcd.print("-- Cursor ON --");
	lcd.cursor(true);
	delay(ui32_lcd_delay);

	lcd.clear();
	lcd << "-- Cursor Home --" << endl;
	lcd.home();
	delay(ui32_lcd_delay);

	lcd.clear();
	lcd.cursor(false);

	for (uint8_t j = 0; j < 4; j++)
	{
		uint8_t i = 0;
		for (i = 0; i < 13; i++)    /// move string to right
		{
			lcd.cursorXY(i, 1);
			lcd << " Hello ";
			delay(100);    /// delay 100ms
		}
		for (; i > 0; i--)    /// move string to left
		{
			lcd.cursorXY(i, 1);
			lcd << " Hello ";
			delay(100);
		}
	}

#endif
#ifdef LCD_PRINT
	const uint8_t uc_val = 0xFF;
	const int32_t i32_val = -456798;
	const float f_val = 1234.89;

//	size_t println(const String &s);
//	size_t println(const char[]);
//	size_t println(char);
//	size_t println(unsigned char, int = DEC);
//	size_t println(int, int = DEC);
//	size_t println(unsigned int, int = DEC);
//	size_t println(long, int = DEC);
//	size_t println(unsigned long, int = DEC);
//	size_t println(double, int = 2);
//	size_t println(const Printable&);
//	size_t println(void);

	lcd.clear();
	lcd << "-- Operator << --" << endl;
	delay(ui32_lcd_delay);

	///	size_t println(const __FlashStringHelper *);
	lcd.clear();
	lcd.println(F("Const char in flash"));
	lcd.println(F("I am in flash !"));
	delay(ui32_lcd_delay);

	lcd.clear();
	lcd << F("-- Print String --") << endl;
	String string("I am a string !");
	lcd.println(string);
	delay(ui32_lcd_delay);

	lcd.clear();
	lcd << "-- Print char --" << endl;
	lcd << "char : " << 'a' << endl;
	delay(ui32_lcd_delay);

	lcd.clear();
	lcd << "-- Print Printable --" << endl;
	lcd << lcd << endl;
	delay(ui32_lcd_delay);

	lcd.clear();
	lcd << "-- Print number --" << endl;
	lcd << "uint8_t: " << uc_val << endl;
	lcd << "uint8_t: 0x" << _HEX(uc_val) << endl;
	lcd << "uint8_t: 0b" << _BIN(uc_val) << endl;
	delay(ui32_lcd_delay);

	lcd.clear();
	lcd << "-- Print number --" << endl;
	lcd << "int32_t: " << i32_val << endl;
	lcd << "int32_t: 0x" << _HEX(i32_val) << endl;
	delay(ui32_lcd_delay);

	lcd.clear();
	lcd << "-- Print float --" << endl;
	lcd << "float: " << f_val << endl;
	delay(ui32_lcd_delay);
#endif

	lcd.clear();
	lcd << _XY(1, 0) << "Thanks for watching" << endl;
	delay(ui32_lcd_delay);
}

/// ------------------------------------------------------------------------------------------------
/// END OF FILE
/// ------------------------------------------------------------------------------------------------
