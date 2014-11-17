/*
 * semaphore_base.hpp
 *
 *  Created on: 17 nov. 2014
 *      Author: Nico_user
 */

#ifndef SEMAPHORE_BASE_HPP_
#define SEMAPHORE_BASE_HPP_

#include "i_semaphore.hpp"
#include "task.hpp"

namespace OS
{

class Semaphore : public I_Semaphore
{
	public:
		/// === PUBLIC ATTRIBUTS	================================================================

		static const TickType_t TIMEOUT_MAX = portMAX_DELAY;

		/// === PUBLIC INTERFACE	================================================================

		virtual bool take(TickType_t timeout_ms = TIMEOUT_MAX);
		virtual bool takeFromISR();

		virtual bool give();
		virtual bool giveFromISR();

		/// === PUBLIC DECLARATIONS	================================================================

		Semaphore(uint8_t n_token);

	protected:
		/// === PROTECTED ATTRIBUTS	================================================================

		SemaphoreHandle_t handle;
};

}

#endif /* SEMAPHORE_BASE_HPP_ */
