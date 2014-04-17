///
/// State Machine State model.
/// Copyright (c) 2013 Nicolas BOUTIN.  All right reserved.
///
/// This library is free software; you can redistribute it and/or
/// modify it under the terms of the GNU Lesser General Public
/// License as published by the Free Software Foundation; either
/// version 2.1 of the License, or (at your option) any later version.
///
/// This library is distributed in the hope that it will be useful,
/// but WITHOUT ANY WARRANTY; without even the implied warranty of
/// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
/// Lesser General Public License for more details.
///
/// You should have received a copy of the GNU Lesser General Public
/// License along with this library; if not, write to the Free Software
/// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
/// ------------------------------------------------------------------------------------------------
///
/// \file	state.cpp
/// \brief	State model.
/// \date	07/04/2014
/// \author	nboutin
///

#include "state.h"
using namespace util;

/// ====================================================================================================================
/// ===	INCLUDES
/// ====================================================================================================================

/// ====================================================================================================================
/// ===	NAMESPACES
/// ====================================================================================================================

/// ====================================================================================================================
/// ===	PUBLIC DEFINITIONS
/// ====================================================================================================================

/// --------------------------------------------------------------------------------------------------------------------
bool State::onEnter()
{
#ifdef __DBG_STATE
//	Log_I("%s(%d) %s", s_name, id, __FUNCTION__);
	cout << __func__ << endl;
#endif
	return true;
}

/// --------------------------------------------------------------------------------------------------------------------
void State::onExit()
{
#ifdef __DBG_STATE
//	Log_I("%s(%d) %s", s_name, id, __FUNCTION__);
//	Log_I("------------------------------");
	cout << __func__ << endl;
	cout << "------------------------------" << endl;
#endif
}

/// --------------------------------------------------------------------------------------------------------------------
void State::inState()
{
#ifdef __DBG_STATE
//	Log_I("%s(%d) %s", s_name, id, __FUNCTION__);
	cout << __func__ << endl;
#endif
}
/// ====================================================================================================================
/// ===	END OF FILE
/// ====================================================================================================================
