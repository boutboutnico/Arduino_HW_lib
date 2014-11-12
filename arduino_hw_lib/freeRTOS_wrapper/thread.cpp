/*
 * thread.cpp
 *
 *  Created on: 31 mars 2014
 *      Author: Nico_user
 */

#include "thread.h"
using namespace OS;

#include "task.h"

Thread::Thread(const char* const name, const uint16_t stack_depth, const UBaseType_t priority)
{
	/// signed char xTaskGenericCreate(
	/// void (*)(void *),
	/// const char *,
	/// unsigned short int,
	/// void *, unsigned char, void * *, unsigned char *, const xMEMORY_REGION *)
	xTaskCreate(Thread::taskfun, name, stack_depth, this, priority, 0);
}

void Thread::taskfun(void* param)
{
	static_cast<Thread*>(param)->run();
}
