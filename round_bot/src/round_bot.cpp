///
/// Main class to manage a round robot with two wheels.
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
/// \file	roud_bot.cpp
/// \brief	Main program to manage a two wheel robot.
/// \date	07/04/2014
/// \author	nboutin
///

/// ------------------------------------------------------------------------------------------------
/// INCLUDES
/// ------------------------------------------------------------------------------------------------
#include "Arduino.h"

/// External library
//#include "Wire.h"

/// Internal library
#include "lcd_i2c.h"

#include "motor_typedef.h"
#include "motor.h"
#include "encoder.h"
#include "PID_v1.h"

#include "GP2D12.h"
#include "SRF05.h"

#include "odometry.h"
//#include "target.h"

/// ------------------------------------------------------------------------------------------------
/// NAMESPACES
/// ------------------------------------------------------------------------------------------------
using namespace arduino_hw_lib;
using namespace motor;

/// ------------------------------------------------------------------------------------------------
/// CONSTANTS
/// ------------------------------------------------------------------------------------------------
static const float f_kp = 3.75;
static const float f_ki = 0.75;
static const float f_kd = 0.025;

/// ------------------------------------------------------------------------------------------------
/// GLOBAL DECLARATIONS
/// ------------------------------------------------------------------------------------------------

void doRightEncoder();
void doLeftEncoder();

/// LCD
//LCD_I2C lcd(0x00, 4, 20);

/// Motors & Encoders
/// dir_pin / cmd_pin / dir
//Motor r_mot(4, 5, MOT_FORWARD);
//Motor l_mot(7, 6, MOT_REVERSE);

/// pin_A / int_pin_A / pin_B / int_func / is_CCW
//Encoder r_enc(3, 1, 9, doRightEncoder, true);
//Encoder l_enc(2, 0, 8, doLeftEncoder, false);

/// PID
/// min = 5 (less no tested)
/// max = 60 (pwm = 255)
//float l_consigne = 50;    /// cm/sec
//float r_consigne = 50;    /// cm/sec
//float theta_consigne = 180;
//
//float l_cmd = 0;
//float r_cmd = 0;
//float theta_cmd = 0;
//
//ST_vel st_vel;
//ST_pos st_pos;
//
//PID l_pid(l_consigne, st_vel.l_vel, l_cmd, f_kp, f_ki, f_kd);
//PID r_pid(r_consigne, st_vel.r_vel, r_cmd, f_kp, f_ki, f_kd);
//PID theta_pid(theta_consigne, st_pos.theta_deg, theta_cmd, 3.75, 0, 1.5);

//--------------------------------------------------
// SENSORS
//--------------------------------------------------
//GP2D12 tel_right(A0);
//GP2D12 tel_left(A1);
//SRF05 sfr05(11, 10);

//--------------------------------------------------
// Others
//--------------------------------------------------
//Odometry odo;
//ST_Sensors st_sensors;
//
//ST_Behavior tst_behavior[BEHAVIOR_COUNT];
//uint8_t ui8_current_behavior = 0;
//uint8_t ui8_current_argument = 0;

//void arbitrator();
//void motor_cmd(const ST_Behavior& i_rst_behavior);
//
//void cruise(ST_Behavior& i_rst_behavior);
//void front_20cm(ST_Behavior& i_rst_behavior);
//void front_30cm(ST_Behavior& i_rst_behavior);
/// SETUP
/// ------------------------------------------------------------------------------------------------

void setup()
{
	//--------------------------------------------------
	// Motors
	//--------------------------------------------------
//	r_mot.begin();
//	r_enc.begin();
//
//	l_mot.begin();
//	l_enc.begin();
//
//	theta_pid.SetOutputLimits(-255, 255);
//	l_pid.SetOutputLimits(-255, 255);
//	r_pid.SetOutputLimits(-255, 255);

	//--------------------------------------------------
	// LCD
	//--------------------------------------------------
//	lcd.begin();
//	lcd.cursor(false);
//	lcd.clear();
//	lcd.backlight(true);

	//--------------------------------------------------
	// Serial
	//--------------------------------------------------
//	Serial.begin(9600);
}

/// ------------------------------------------------------------------------------------------------
/// LOOP
/// ------------------------------------------------------------------------------------------------
void loop()
{
	//--------------------------------------------------
	//	Input
	//--------------------------------------------------
//	odo.compute(l_enc.getCount(), r_enc.getCount());
//	st_vel = odo.getVel();
//	st_pos = odo.getPos();
//
//	st_sensors.ui8_tel_left = tel_left.getDistanceAverage_cm();
//	st_sensors.ui8_tel_right = tel_right.getDistanceAverage_cm();
//	st_sensors.ui16_sfr05 = sfr05.getDistanceAverage_cm();

	//--------------------------------------------------
	//	Subsumption behavior
	//--------------------------------------------------
//	front_20cm(tst_behavior[FRONT_20]);
//	front_30cm(tst_behavior[FRONT_30]);
//	cruise(tst_behavior[CRUISE]);
//
//	arbitrator();

	//--------------------------------------------------
	//	Print LCD
	//--------------------------------------------------
	static uint32_t ui32_lcd_time = 0;
	if (millis() > ui32_lcd_time)
	{
		ui32_lcd_time += 200;

		// Sensors
//		lcd << _XY(0, 0) << F("TL:") << (uint8_t) st_sensors.ui8_tel_left;
//		lcd << _XY(14, 0) << F("TR:") << (uint8_t) st_sensors.ui8_tel_right;
//		lcd << _XY(7, 0) << F("UF:") << (uint16_t) st_sensors.ui16_sfr05;
//
//		// Subsumption behavior
//		lcd << _XY(0, 1) << F("     ") << tc_behavior[ui8_current_behavior];
//		lcd << _XY(10, 1) << F("     ") << tc_argument[ui8_current_argument];
//
//		// Speed
//		lcd << _XY(0, 2) << F("VL") << (uint32_t) st_vel.l_vel;
//		lcd << _XY(7, 2) << F("VR:") << (uint32_t) st_vel.r_vel;
//
//		// Position
//		lcd << _XY(0, 3) << F("X:") << (uint32_t) st_pos.x;
//		lcd << _XY(7, 3) << F("Y:") << (uint32_t) st_pos.y;
//		lcd << _XY(14, 3) << F("T:") << (uint16_t) (st_pos.theta_deg);
	}

	//--------------------------------------------------
	//	Print Serial
	//--------------------------------------------------
//	static uint32_t serialTime = 0;
//	if(millis() > serialTime /*&& serialTime <= 2000*/)
//	{
//		Serial.print(serialTime);
//		Serial.print("\t");
//
//		Serial.print(l_consigne);
//		Serial.print("\t");
//		Serial.print(st_vel.l_vel);
//		Serial.print("\t");
//		Serial.println(l_cmd);
//
//		Serial.print(theta_consigne);
//		Serial.print("\t");
//		Serial.print(st_pos.theta_deg);
//		Serial.print("\t");
//		Serial.println(theta_cmd);
//
//		serialTime += 50;
//	}

	delay(50);    //50ms
}

//--------------------------------------------------
//	Subsumption task
//--------------------------------------------------
//void motor_cmd(const ST_Behavior& i_rst_behavior)
//{
//	static const uint8_t ui8_turn_angle = 5;
//	static uint8_t ui8_stack_reverse = 0;
//
//	switch (i_rst_behavior.e8_arg)
//	{
//	case AHEAD:
//		l_consigne = i_rst_behavior.e8_cmd;    //cm/sec
//		r_consigne = i_rst_behavior.e8_cmd;    //cm/sec
//		theta_consigne = st_pos.theta_deg;
//		break;
//
//	case RIGHT_TURN:
//		l_consigne = i_rst_behavior.e8_cmd;    //cm/sec
//		r_consigne = -i_rst_behavior.e8_cmd;    //cm/sec
//		theta_consigne = st_pos.theta_deg - ui8_turn_angle;    //Deg
//		ui8_stack_reverse = 0;
//		break;
//
//	case LEFT_TURN:
//		l_consigne = -i_rst_behavior.e8_cmd;    //cm/sec
//		r_consigne = i_rst_behavior.e8_cmd;    //cm/sec
//		theta_consigne = st_pos.theta_deg + ui8_turn_angle;    //Deg
//		ui8_stack_reverse = 0;
//		break;
//
//	case REVERSE:
//		l_consigne = -i_rst_behavior.e8_cmd;    //cm/sec
//		r_consigne = -i_rst_behavior.e8_cmd;    //cm/sec
//
//		if (ui8_stack_reverse++ >= 3)
//		{
//			ST_Behavior st_behavior = { TURN_SPEED, TURN_180, true };
//			motor_cmd(st_behavior);
//			ui8_stack_reverse = 0;
//		}
//		break;
//
//	case TURN_180:
//		l_consigne = -i_rst_behavior.e8_cmd;    //cm/sec
//		r_consigne = i_rst_behavior.e8_cmd;    //cm/sec
//		theta_consigne = st_pos.theta_deg + 180;    //Deg
//		break;
//	}
//
//	l_pid.Compute();
//	r_pid.Compute();
//	theta_pid.Compute();
//
//	l_mot.command((int16_t) l_cmd + theta_cmd);
//	r_mot.command((int16_t) r_cmd - theta_cmd);
//}
//
//void arbitrator()
//{
//	uint8_t ui8_idx;
//	for (ui8_idx = 0; ui8_idx < BEHAVIOR_COUNT; ui8_idx++)
//	{
//		if (tst_behavior[ui8_idx].b_request_cmd == true) break;
//	}
//
//	ui8_current_behavior = ui8_idx;
//	ui8_current_argument = tst_behavior[ui8_idx].e8_arg;
//
//	motor_cmd(tst_behavior[ui8_idx]);
//}
//
//void front_30cm(ST_Behavior& i_rst_behavior)
//{
//	static const uint16_t ui16_threshold_distance = 30;
//	uint8_t ui8_result = 0;
//
//	if (st_sensors.ui8_tel_left <= ui16_threshold_distance) ui8_result |= 0x04;    /// 0b100;
//	if (st_sensors.ui16_sfr05 <= ui16_threshold_distance) ui8_result |= 0x02;    ///0b010;
//	if (st_sensors.ui8_tel_right <= ui16_threshold_distance) ui8_result |= 0x01;    ///0b001;
//
//	i_rst_behavior.b_request_cmd = true;
//
////	Serial.print("ui8_result");
////	Serial.println(ui8_result);
//
//	switch (ui8_result)
//	{
//	case 4:
//	case 6:
//		i_rst_behavior.e8_arg = RIGHT_TURN;
//		i_rst_behavior.e8_cmd = TURN_SPEED;
//		break;
//
//	case 2:
//	case 7:
//		i_rst_behavior.e8_arg = AHEAD;
//		i_rst_behavior.e8_cmd = HALF_SPEED;
//		break;
//
//	case 1:
//	case 3:
//		i_rst_behavior.e8_arg = LEFT_TURN;
//		i_rst_behavior.e8_cmd = TURN_SPEED;
//		break;
//
//	case 0:
//	default:
//		i_rst_behavior.b_request_cmd = false;
//		break;
//	}
//}
//
//void front_20cm(ST_Behavior& i_rst_behavior)
//{
//	static const uint8_t ui8_threshold_distance = 20;
//	uint8_t ui8_result = 0;
//
//	if (st_sensors.ui8_tel_left <= ui8_threshold_distance) ui8_result |= 0x04;
//	if (st_sensors.ui16_sfr05 <= ui8_threshold_distance) ui8_result |= 0x02;
//	if (st_sensors.ui8_tel_right <= ui8_threshold_distance) ui8_result |= 0x01;
//
//	i_rst_behavior.b_request_cmd = true;
//
//	switch (ui8_result)
//	{
//	case 4:
//	case 6:
//		i_rst_behavior.e8_arg = RIGHT_TURN;
//		i_rst_behavior.e8_cmd = TURN_SPEED;
//		break;
//
//	case 7:
//		i_rst_behavior.e8_arg = AHEAD;
//		i_rst_behavior.e8_cmd = HALF_SPEED;
//		break;
//
//	case 1:
//	case 3:
//		i_rst_behavior.e8_arg = LEFT_TURN;
//		i_rst_behavior.e8_cmd = TURN_SPEED;
//		break;
//
//	case 2:
//		i_rst_behavior.e8_arg = REVERSE;
//		i_rst_behavior.e8_cmd = REVERSE_SPEED;
//		break;
//
//	case 0:
//	default:
//		i_rst_behavior.b_request_cmd = false;
//		break;
//	}
//}

//void cruise(ST_Behavior& i_rst_behavior)
//{
//	i_rst_behavior.b_request_cmd = true;
//	i_rst_behavior.e8_arg = AHEAD;
//	i_rst_behavior.e8_cmd = TOP_SPEED;
//}

//--------------------------------------------------
//	Interrupt
//--------------------------------------------------

//void doRightEncoder()
//{
//	r_enc.update();
//}
//
//void doLeftEncoder()
//{
//	l_enc.update();
//}

//--------------------------------------------------
//	test
//--------------------------------------------------

//--------------------------------------------------
//	debug
//--------------------------------------------------

/*****************************************************************************
 * END OF FILE
 *****************************************************************************/
