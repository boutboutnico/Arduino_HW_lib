/*
 * software_timer.cpp
 *
 *  Created on: 14 nov. 2014
 *      Author: Nico_user
 */

#include "software_timer.hpp"
using namespace OS;

#include "task.hpp"

Software_Timer::Software_Timer(	char const * const name,
								TickType_t time_ms,
								bool auto_reload,
								timer_callback_t callback)
{
	///	 TimerHandle_t xTimerCreate
	///	  ( const char * const pcTimerName,
	///		const TickType_t xTimerPeriod,
	///		const UBaseType_t uxAutoReload,
	///		void * const pvTimerID,
	///		TimerCallbackFunction_t pxCallbackFunction );
	handle = xTimerCreate(name, OS::ms_to_ticks(time_ms), auto_reload, this, callback);
}

//void Software_Timer::callback(void* param)
//{
//	reinterpret_cast<Software_Timer*>(param)->run();
//}

bool Software_Timer::start()
{
	return xTimerStart(handle, 0);
}
