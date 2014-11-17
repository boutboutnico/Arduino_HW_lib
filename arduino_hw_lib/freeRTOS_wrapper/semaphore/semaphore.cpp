/*
 * semaphore.cpp
 *
 *  Created on: 17 nov. 2014
 *      Author: Nico_user
 */

#include "semaphore.hpp"
using namespace OS;

bool Semaphore::take(TickType_t timeout_ms)
{
	if (timeout_ms == TIMEOUT_MAX)
	{
		return xSemaphoreTake(handle, TIMEOUT_MAX);
	}
	else
	{
		return xSemaphoreTake(handle, OS::ms_to_ticks(timeout_ms));
	}
}

/// ------------------------------------------------------------------------------------------------

bool Semaphore::takeFromISR()
{
	return false;
}

/// ------------------------------------------------------------------------------------------------

bool Semaphore::give()
{
	return xSemaphoreGive(handle);
}

/// ------------------------------------------------------------------------------------------------

bool Semaphore::giveFromISR()
{
	return false;
}

/// ------------------------------------------------------------------------------------------------

Semaphore::Semaphore(uint8_t n_token)
{
	if (n_token == 0)
	{
		handle = xSemaphoreCreateBinary();
	}
	else
	{
		handle = xSemaphoreCreateCounting(n_token, n_token);
	}
}

/// ------------------------------------------------------------------------------------------------
