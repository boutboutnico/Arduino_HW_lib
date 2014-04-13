/*
 * thread.h
 *
 *  Created on: 31 mars 2014
 *      Author: Nico_user
 */

#ifndef THREAD_H_
#define THREAD_H_

#include "type_definitions.h"
#include "FreeRTOS.h"
#include "task.h"

namespace OS
{

class Thread
{
public:
	Thread(const int8 * const name, const uint16 stack_depth, const UBaseType_t priority);

	virtual void run() = 0;

	static void taskfun(void* param);

private:

};

}
#endif /* THREAD_H_ */
