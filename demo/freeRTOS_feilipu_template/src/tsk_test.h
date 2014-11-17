/*
 * tsk_test.H
 *
 *  Created on: 31 mars 2014
 *      Author: Nico_user
 */

#ifndef TSK_TEST_H_
#define TSK_TEST_H_

#include "task.hpp"
#include "semaphore.hpp"
#include "software_timer.hpp"

class TSK_T1 : public OS::Task
{
	public:
		/// === PUBLIC ATTRIBUTS	================================================================

		static const uint16_t STACK_SIZE = 128;
		static const UBaseType_t STACK_PRIORITY = 1;

		static const TickType_t TIMER_DURATION = 50;

		static const uint8_t SEMAPHORE_N_TOKEN = 0;
		static const uint16_t SEMAPHORE_TIMEOUT = 10000;

		/// === PUBLIC DECLARATIONS	================================================================

		TSK_T1();

		virtual void run();

	private:
		/// === PRIVATE DECLARATIONS	============================================================

		static void callback(TimerHandle_t pxTimer);

		/// === PRIVATE ATTRIBUTS	================================================================

		OS::Software_Timer timer;
		static OS::Semaphore sem;
};

/// ------------------------------------------------------------------------------------------------

class TSK_Test1 : public OS::Task
{
	public:
		TSK_Test1()
				: Task("TSK_Test1", 256, 2)
		{

		}
		virtual void run();
};

#endif /* TSK_TEST_H_ */
