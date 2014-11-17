/*
 * i_semaphore.hpp
 *
 *  Created on: 17 nov. 2014
 *      Author: Nico_user
 */

#ifndef I_SEMAPHORE_HPP_
#define I_SEMAPHORE_HPP_

#include "FreeRTOS.h"
#include "semphr.h"

namespace OS
{

class I_Semaphore
{
	public:
		/// === PUBLIC INTERFACE	================================================================

		virtual bool take(TickType_t timeout) = 0;
		virtual bool takeFromISR() = 0;

		virtual bool give() = 0;
		virtual bool giveFromISR() = 0;
};

}

#endif /* I_SEMAPHORE_HPP_ */
