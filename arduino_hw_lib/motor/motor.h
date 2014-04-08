/*************************************************************************//**
 * @file 	motor.h
 * @brief	xx
 * @author	Nicolas BOUTIN
 * @date	01/11/2012
 * @module	Motor
 *****************************************************************************/
#ifndef __MOTOR__
#define __MOTOR__

/*****************************************************************************
 * INCLUDE
 *****************************************************************************/
#include "Arduino.h"

/*****************************************************************************
 * DEFINITION
 *****************************************************************************/
#define MOT_FORWARD LOW
#define MOT_REVERSE HIGH

// #define __DBG_MOT

/*****************************************************************************
 * CLASS
 *****************************************************************************/
/**
 * @class 	xx
 * @brief	xx
 * @author	boutboutnico
 * @date	25 juil. 2012
 */
class Motor
{
private:
	uint8_t ui8_dir_pin;
	uint8_t ui8_cmd_pin;

	boolean b_dir;
	boolean b_current_dir;

public:
	Motor(const uint8_t i_ui8_dir_pin, const uint8_t i_ui8_cmd_pin, const boolean i_b_dir);

	void begin();
	void command(const int16_t i_i16_command);
};

#endif //__MOTOR__
/*****************************************************************************
 * END OF FILE
 *****************************************************************************/
