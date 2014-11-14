/*
 * software_timer.hpp
 *
 *  Created on: 14 nov. 2014
 *      Author: Nico_user
 */

#ifndef SOFTWARE_TIMER_HPP_
#define SOFTWARE_TIMER_HPP_

#include "FreeRTOS.h"
#include "timers.h"

namespace OS
{

class Software_Timer
{
	public:
		typedef void (*timer_callback_t)(TimerHandle_t pxTimer);

		Software_Timer(	char const * const name,
						TickType_t time_ms,
						bool auto_reload,
						timer_callback_t callback);

//		static void callback(TimerHandle_t pxTimer);
//		virtual void run() = 0;

		bool start();

	private:
		TimerHandle_t handle;
};

}

#endif /* SOFTWARE_TIMER_HPP_ */
