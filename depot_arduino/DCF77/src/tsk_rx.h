/*
 * tsk_test.H
 *
 *  Created on: 31 mars 2014
 *      Author: Nico_user
 */

#ifndef TSK_RX_H_
#define TSK_RX_H_

/// === INCLUDES	================================================================================

#include "task.hpp"
#include "software_timer.hpp"

/// === CLASS	====================================================================================

class TSK_RX : public OS::Task
{
	public:
		/// === PUBLIC DECLARATIONS	================================================================

		TSK_RX();

		virtual void run();

	private:

		static void callback(TimerHandle_t pxTimer);

		/// === PRIVATE DECLARATIONS	============================================================

		OS::Software_Timer timer;
};

#endif /// TSK_RX_H_/// === END OF FILE	================================================================================
