/*************************************************************************//**
 * @file 	motor.cpp
 * @brief	xx
 * @author	Nicolas BOUTIN
 * @date	01/11/2012
 * @module	Motor
 *****************************************************************************/

/*****************************************************************************
 * INCLUDE
 *****************************************************************************/
#include "motor.h"

/*****************************************************************************
 * GLOBALE VARIABLE
 *****************************************************************************/

/*****************************************************************************
 * PUBLIC IMPLEMENTATION
 *****************************************************************************/

/**
 *
 * @param i_ui8_dir_pin
 * @param i_ui8_cmd_pin
 * @param i_b_dir
 */
Motor::Motor(const uint8_t i_ui8_dir_pin, const uint8_t i_ui8_cmd_pin, const boolean i_b_dir)
{
	ui8_dir_pin = i_ui8_dir_pin;
	ui8_cmd_pin = i_ui8_cmd_pin;

	b_dir = i_b_dir;
	b_current_dir = i_b_dir;
}

/**
 *
 */
void Motor::begin()
{
	pinMode(ui8_dir_pin, OUTPUT);
	pinMode(ui8_cmd_pin, OUTPUT);
	digitalWrite(ui8_dir_pin, b_dir);
	analogWrite(ui8_cmd_pin, 0);
}

/**
 *
 * @param i_ui8_command
 */
void Motor::command(const int16_t i_i16_command)
{
	//--------------------------------------------------
	// Change direction only when needed
	//--------------------------------------------------
	switch(b_dir){
	case MOT_FORWARD:
		if(i_i16_command < 0 && b_current_dir != MOT_REVERSE)
		{
			b_current_dir = MOT_REVERSE;
			digitalWrite(ui8_dir_pin, b_current_dir);

#ifdef __DBG_MOT
			Serial.print("Change dir 1 :");
			Serial.println(b_current_dir);
#endif
		}
		else if(i_i16_command >= 0 && b_current_dir != MOT_FORWARD)
		{
			b_current_dir = MOT_FORWARD;
			digitalWrite(ui8_dir_pin, b_current_dir);

#ifdef __DBG_MOT
			Serial.print("Change dir 2 :");
			Serial.println(b_current_dir);
#endif
		}
		break;

	case MOT_REVERSE:
		if(i_i16_command < 0 && b_current_dir != MOT_FORWARD)
		{
			b_current_dir = MOT_FORWARD;
			digitalWrite(ui8_dir_pin, b_current_dir);

#ifdef __DBG_MOT
			Serial.print("Change dir 3 :");
			Serial.println(b_current_dir);
#endif
		}
		else if(i_i16_command >= 0 && b_current_dir != MOT_REVERSE)
		{
			b_current_dir = MOT_REVERSE;
			digitalWrite(ui8_dir_pin, b_current_dir);

#ifdef __DBG_MOT
			Serial.print("Change dir 4 :");
			Serial.println(b_current_dir);
#endif
		}
		break;
	}

	//--------------------------------------------------
	// Apply command
	//--------------------------------------------------
	// Forward
	if(i_i16_command >= 0)
	{
		analogWrite(ui8_cmd_pin, i_i16_command);
	}
	// Backward
	else
	{
		analogWrite(ui8_cmd_pin, abs(i_i16_command));
	}

#ifdef __DBG_MOT
	Serial.print("cmd ");
	Serial.println(i_i16_command);
#endif
}

/*****************************************************************************
 * PRIVATE IMPLEMENTATION
 *****************************************************************************/

/*****************************************************************************
 * END OF FILE
 *****************************************************************************/
