/*
 * thread.cpp
 *
 *  Created on: 31 mars 2014
 *      Author: Nico_user
 */

#include "thread.h"

using namespace OS;

Thread::Thread(const int8 * const name, const uint16 stack_depth, const UBaseType_t priority)
{
	xTaskCreate(Thread::taskfun, name, stack_depth, this, priority, 0);
}

void Thread::taskfun(void* param)
{
	static_cast<Thread*>(param)->run();
}
