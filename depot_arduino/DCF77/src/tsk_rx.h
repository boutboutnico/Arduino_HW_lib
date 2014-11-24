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

enum E_Bit_Type
{
	ZERO = 0x00,
	ONE,
	TOO_SHORT,
	SYNCHRONIZATION
};

/// === CLASS	====================================================================================

class TSK_RX : public OS::Task
{
	public:
		/// === PUBLIC ATTRIBUTS	================================================================

		static const uint16_t STACK_SIZE = 128;
		static const UBaseType_t STACK_PRIORITY = 1;

		static const TickType_t TIMER_DURATION = 500;

		/// === PUBLIC DECLARATIONS	================================================================

		TSK_RX();

		virtual void run();

	private:
		/// === PRIVATE DECLARATIONS	============================================================

		static void callback(TimerHandle_t pxTimer)__attribute__ ((pure));

		/// === PRIVATE DECLARATIONS	============================================================

		OS::Software_Timer timer;
		static E_Bit_Type e_bit_type;
		static uint8_t count_high_;
		static uint8_t count_low_;
};

#endif /// TSK_RX_H_/// === END OF FILE	================================================================================
