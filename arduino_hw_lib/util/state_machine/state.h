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
/// \file	state.h
/// \brief	State model.
/// \date	07/04/2014
/// \author	nboutin
///

#ifndef STATE_H_
#define STATE_H_

/// ====================================================================================================================
/// ===	INCLUDES
/// ====================================================================================================================
#include "sp2_common.h"

/// ====================================================================================================================
/// ===	NAMESPACES
/// ====================================================================================================================

/// \namespace	util
///	\brief		Contains utilitary classes.
namespace util
{

/// ====================================================================================================================
/// ===	CLASS
/// ====================================================================================================================
template<UCHAR8 n_state, UCHAR8 n_transition> class State_Machine;

/// ====================================================================================================================
/// ===	CLASS
/// ====================================================================================================================

/// \class	I_State
///	\brief	State interface.
/// \date	17/04/2014
/// \author	nboutin & bpayen
class I_State
{
	public:
		/// ============================================================================================================
		/// ===	PUBLIC DECLARATIONS
		/// ============================================================================================================

		/// \brief	Called each time we enter the state from another state
		/// \return	TRUE if success, FALSE otherwise.
		virtual bool onEnter() = 0;

		/// \brief	Called each time we exit the state for another state.
		virtual void onExit() = 0;

		/// \brief	Called each time a transition lead to this state.
		virtual void inState() = 0;
};

/// ====================================================================================================================
/// ===	CLASS
/// ====================================================================================================================

/// \class	State
///	\brief	Model a state in State_Machine.
/// \date	17/04/2014
/// \author	nboutin & bpayen
class State : public I_State
{
		/// Only State_Machine can change a State id.
		template<UCHAR8 n_state, UCHAR8 n_transition> friend class State_Machine;

	public:
		/// ============================================================================================================
		/// ===	PUBLIC CONSTANTS
		/// ============================================================================================================
		static const UCHAR8 ID_DEFAULT = 0xFF;

		/// ============================================================================================================
		/// ===	PUBLIC DECLARATIONS
		/// ============================================================================================================

		State()
				: id(ID_DEFAULT)
		{
		}

		virtual bool onEnter();

		virtual void onExit();

		virtual void inState();

		UCHAR8 getId() const
		{
			return id;
		}

#ifdef __DBG_STATE
		/// Set a name to a state so debug is easier.

		static const UCHAR8 NAME_LENGTH = 24;

		template<UCHAR8 Len>
		void setName(const CHAR8 (&name)[Len])
		{
			if (Len <= NAME_LENGTH)
			{
				strncpy(s_name, &name[0], sizeof(CHAR8) * Len);
			}
		}
		CHAR8 s_name[NAME_LENGTH];
#endif

	private:
		/// ============================================================================================================
		/// ===	PRIVATE DECLARATIONS
		/// ============================================================================================================

		/// TODO protection, only accessible from State_Machine, use friend key word.
		void setId(const UCHAR8 iu8_id)
		{
			id = iu8_id;
		}

		/// ============================================================================================================
		/// ===	PRIVATE ATTRIBUTS
		/// ============================================================================================================
		UCHAR8 id;
};

/// ====================================================================================================================
/// ===	CLASS
/// ====================================================================================================================

/// \class	State_Timed
///	\brief	Model a state with a timeout.
/// \date	17/04/2014
/// \author	nboutin & bpayen
//class State_Timed: public State
//{
//	public:
//		/// ============================================================================================================
//		/// ===	PUBLIC DECLARATIONS
//		/// ============================================================================================================
//		State_Timed(OS::OS_Timer& timer, const USHORT16 ius_duration_ms)
//				: 	os_tim(timer),
//					TIMER_DURATION_MS(ius_duration_ms)
//		{
//		}
//
//		virtual bool onEnter()
//		{
//			os_tim.stop();
//			os_tim.change(OS::ms_to_tick_os(TIMER_DURATION_MS));
//			os_tim.start();
//			return true;
//		}
//
//		virtual void onExit()
//		{
//			os_tim.stop();
//		}
//
//	private:
//		/// ============================================================================================================
//		/// ===	PRIVATE ATTRIBUTS
//		/// ============================================================================================================
//
//		OS::OS_Timer& os_tim;
//		const USHORT16 TIMER_DURATION_MS;
//};

}

#endif	/// STATE_H_/// ====================================================================================================================
/// ===	END OF FILE
/// ====================================================================================================================
