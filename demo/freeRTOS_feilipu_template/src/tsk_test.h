/*
 * tsk_test.H
 *
 *  Created on: 31 mars 2014
 *      Author: Nico_user
 */

#ifndef TSK_TEST_H_
#define TSK_TEST_H_

#include "task.hpp"

class TSK_RX : public OS::Task
{
	public:

//		static const int8_t name[];

		TSK_RX()
				: Task("TSK_Test", 256, 3)
		{

		}
		virtual void run();
};

class TSK_Test1 : public OS::Task
{
	public:
//		static const int8_t name[];

		TSK_Test1()
				: Task("TSK_Test1", 256, 2)
		{

		}
		virtual void run();
};

#endif /* TSK_TEST_H_ */
