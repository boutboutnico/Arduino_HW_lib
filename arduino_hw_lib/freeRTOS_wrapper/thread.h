/*
 * thread.h
 *
 *  Created on: 31 mars 2014
 *      Author: Nico_user
 */

#ifndef THREAD_H_
#define THREAD_H_

#include "FreeRTOS.h"
#include "task.h"

namespace OS
{

class Thread
{
	public:
		Thread(const char* const name, const uint16_t stack_depth, const UBaseType_t priority);

		virtual void run() = 0;

		static void taskfun(void* param);

	private:

};

}
#endif /* THREAD_H_ */
