/*
 * thread.h
 *
 *  Created on: 31 mars 2014
 *      Author: Nico_user
 */

#ifndef TASK_H_
#define TASK_H_

#include "FreeRTOS.h"
#include "task.h"

#define bitSet(value, bit) ((value) |= (1UL << (bit)))
#define bitClear(value, bit) ((value) &= ~(1UL << (bit)))

namespace OS
{

static TickType_t ms_to_ticks(TickType_t time_ms)
{
	return time_ms / portTICK_PERIOD_MS;
}

static void delayUntil(TickType_t time_ms)
{
	TickType_t xLastWakeTime = xTaskGetTickCount();

	vTaskDelayUntil(&xLastWakeTime, ms_to_ticks(time_ms));
}

/// === CLASS	====================================================================================

class Task
{
	public:
		Task(const char* const name, const uint16_t stack_depth, const UBaseType_t priority);

		static void callback(void* param);
		virtual void run() = 0;

	private:

};

}
#endif	/// TASK_H_
