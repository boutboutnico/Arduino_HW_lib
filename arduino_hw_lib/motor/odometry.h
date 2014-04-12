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
/// \file	odometry.h
/// \brief	Library to compute odometry.
/// \date	12/04/2014
/// \author	nboutin
///

#ifndef ODOMETRY_H_
#define ODOMETRY_H_

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

/// ------------------------------------------------------------------------------------------------
/// CLASS
/// ------------------------------------------------------------------------------------------------

///
/// \class 		Encoder
/// \brief		Class to compute odometry.
/// \date		12/04/2014
/// \author		nboutin
///
class Odometry
{
	public:
		/// ----------------------------------------------------------------------------------------
		/// PUBLIC DECLARATIONS
		/// ----------------------------------------------------------------------------------------

		Odometry(	const float if_wheel_distance_mm,
					const float if_n_clicks_left_per_cm,
					const float if_n_clicks_right_per_cm);

		void compute(const int32_t l_enc, const int32_t r_enc);

		const motor::ST_pos& getPos() const;
		const motor::ST_vel& getVel() const;

	private:

		/// ----------------------------------------------------------------------------------------
		/// PRIVATE ATTRIBUTS
		/// ----------------------------------------------------------------------------------------

		const float WHEEL_DISTANCE_MM;
		const float N_CLICKS_LEFT_PER_CM;
		const float N_CLICKS_RIGHT_PER_CM;

		motor::ST_pos st_pos;
		float theta_rad;    /// bot heading

		motor::ST_vel st_vel;

		uint32_t last_time;

		int32_t l_last_enc;
		int32_t r_last_enc;
};

}

#endif	/// ODOMETRY_H_
/// ------------------------------------------------------------------------------------------------
/// END OF FILE
/// ------------------------------------------------------------------------------------------------
