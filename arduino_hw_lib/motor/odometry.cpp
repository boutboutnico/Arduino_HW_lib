///
/// Class that provides basic function to do odometry.
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
/// \file	odometry.cpp
/// \brief	Library to compute odometry.
/// \date	12/04/2014
/// \author	nboutin
///

#include "odometry.h"
using namespace arduino_hw_lib;

/// ------------------------------------------------------------------------------------------------
/// INCLUDES
/// ------------------------------------------------------------------------------------------------
#include "math.h"

/// ------------------------------------------------------------------------------------------------
/// NAMESPACES
/// ------------------------------------------------------------------------------------------------
using namespace motor;

/// ------------------------------------------------------------------------------------------------
/// PUBLIC DEFINITIONS
/// ------------------------------------------------------------------------------------------------

Odometry::Odometry(	const float if_wheel_distance_mm,
					const float if_n_clicks_left_per_cm,
					const float if_n_clicks_right_per_cm)
		: 	WHEEL_DISTANCE_MM(if_wheel_distance_mm),
			N_CLICKS_LEFT_PER_CM(if_n_clicks_left_per_cm),
			N_CLICKS_RIGHT_PER_CM(if_n_clicks_right_per_cm),
			theta_rad(0),
			last_time(0),
			l_last_enc(0),
			r_last_enc(0)
{
	st_pos.theta_deg = 0;
	st_pos.x = 0;
	st_pos.y = 0;

	st_vel.l_vel = 0;
	st_vel.r_vel = 0;
}

void Odometry::compute(const int32_t l_enc, const int32_t r_enc)
{
	float left_cm = 0.0;
	float right_cm = 0.0;
	float dist_cm = 0.0;

	uint32_t now_time = millis();

	/// sample the left and right encoder counts as close together in time as possible
	/// determine how many ticks since our last sampling
	int32_t l_delta_enc = l_enc - l_last_enc;
	int32_t r_delta_enc = r_enc - r_last_enc;

	/// and update last sampling for next time
	l_last_enc = l_enc;
	r_last_enc = r_enc;

	/// convert longs to floats and ticks to millimeter
	left_cm = (float) (l_delta_enc / N_CLICKS_LEFT_PER_CM);
	right_cm = (float) (r_delta_enc / N_CLICKS_RIGHT_PER_CM);

	/// calculate distance we have traveled since last sampling
	dist_cm = (left_cm + right_cm) / 2.0;

	/// accumulate total rotation around our center
	theta_rad += (left_cm - right_cm) / WHEEL_DISTANCE_MM;

	/// and clip the rotation to plus or minus 360 degrees
	theta_rad -= (float) ((int) (theta_rad / TWO_PI)) * TWO_PI;
	st_pos.theta_deg = theta_rad * RAD_TO_DEG;

	/// now calculate and accumulate our position in millimeter
	st_pos.y += (dist_cm * cos(theta_rad));
	st_pos.x += (dist_cm * sin(theta_rad));
//
//	/// How long since we last calculated
//	float delta_time = (float) (now_time - last_time);
//
//	/// Calcul velocity for left and right
//	st_vel.l_vel = (left_cm * 1000) / delta_time;    /// cm/sec
//	st_vel.r_vel = (right_cm * 1000) / delta_time;    /// cm/sec
//
//	// Remember for last time
//	last_time = now_time;

//	Serial.println(l_samp);
//	Serial.println(r_samp);
//	Serial.println(l_delta_enc);
//	Serial.println(r_delta_enc);
//	Serial.println(left_cm, 2);
//	Serial.println(right_cm, 2);
//	Serial.println(dist_cm, 2);
//	Serial.println(theta, 2);
//	Serial.println(x_pos, 2);
//	Serial.println(y_pos, 2);
//	Serial.println();
}

const ST_pos& Odometry::getPos() const
{
	return st_pos;
}

const ST_vel& Odometry::getVel() const
{
	return st_vel;
}

/// ------------------------------------------------------------------------------------------------
/// PRIVATE DEFINITIONS
/// ------------------------------------------------------------------------------------------------

/// ------------------------------------------------------------------------------------------------
/// END OF FILE
/// ------------------------------------------------------------------------------------------------

