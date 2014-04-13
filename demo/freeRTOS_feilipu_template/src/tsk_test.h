/*
 * tsk_test.H
 *
 *  Created on: 31 mars 2014
 *      Author: Nico_user
 */

#ifndef TSK_TEST_H_
#define TSK_TEST_H_

#include "thread.h"

class TSK_Test: public OS::Thread
{
public:
	TSK_Test() :
			Thread("TSK_Test", 256, 3)
	{

	}
	virtual void run();
};

class TSK_Test1: public OS::Thread
{
public:
	TSK_Test1() :
			Thread("TSK_Test1", 256, 2)
	{

	}
	virtual void run();
};

#endif /* TSK_TEST_H_ */
