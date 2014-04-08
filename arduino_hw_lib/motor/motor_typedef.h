///
/// \file	motor_typedef.h
/// \brief	Type definition to work with motor library.
/// \date	08/04/2014
/// \author	nboutin
///

#ifndef MOTOR_TYPEDEF_H_
#define MOTOR_TYPEDEF_H_

/// ------------------------------------------------------------------------------------------------
/// INCLUDES
/// ------------------------------------------------------------------------------------------------
#include "Arduino.h"

/// ------------------------------------------------------------------------------------------------
/// NAMESPACE
/// ------------------------------------------------------------------------------------------------

/// \namespace	motor
///	\brief		Type definition to work with motor.
namespace motor
{

/// \enum	E_Direction
/// \brief	Motor and Encoder direction.
enum E_Direction
{
	DIR_FORWARD = LOW,
	DIR_REVERSE = HIGH
};

enum E8_Behavior
{
	FRONT_20 = 0x0,
	FRONT_30,
	CRUISE,
	BEHAVIOR_COUNT
};

static const char tc_behavior[BEHAVIOR_COUNT][16] = { "FRONT_20", "FRONT_30", "CRUISE" };

enum E8_Command
{
	TOP_SPEED = 40,
	HALF_SPEED = TOP_SPEED / 2,
	ZERO_SPEED = 0,
	TURN_SPEED = 15,
	REVERSE_SPEED = 15
};

enum E8_Argument
{
	AHEAD = 0x00,
	RIGHT_TURN,
	LEFT_TURN,
	TURN_180,
	REVERSE,
	ARGUMENT_COUNT
};

static const char tc_argument[ARGUMENT_COUNT][16] = { "AHEAD", "RIGHT_TURN", "LEFT_TURN",
														"TURN_180", "REVERSE" };

//--------------------------------------------------
//	Structure
//--------------------------------------------------
struct ST_Sensors
{
		uint8_t ui8_tel_left;
		uint8_t ui8_tel_right;
		uint16_t ui16_sfr05;
};

struct ST_Behavior
{
		E8_Command e8_cmd;
		E8_Argument e8_arg;
		boolean b_request_cmd;
};

struct ST_pos
{
		float theta_deg;
		float x;
		float y;
};

struct ST_traj
{
		float target_distance;
		float heading_error_rad;
};

struct ST_vel
{
		float l_vel;
		float r_vel;
};

}

#endif /* MOTOR_TYPEDEF_H_ */
