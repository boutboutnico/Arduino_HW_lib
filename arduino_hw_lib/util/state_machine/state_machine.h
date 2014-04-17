///
/// State Machine model
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
/// \file	state_machine.h
/// \brief	State machine model.
/// \date	07/04/2014
/// \author	nboutin
///

#ifndef STATE_MACHINE_H_
#define STATE_MACHINE_H_

/// ====================================================================================================================
/// ===	INCLUDES
/// ====================================================================================================================
#include "state.h"
#include "transition.h"
#include "state_machine_helper.h"

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

/// \class	I_State_Machine
///	\brief	State machine Interface.
/// \date	17/04/2017
/// \author	nboutin & bpayen
class I_State_Machine
{
public:
	/// ============================================================================================================
	/// ===	PUBLIC INTERFACE
	/// ============================================================================================================

	virtual bool add(State& src, State& dst, Transition& trans) = 0;
	virtual bool remove(Transition& trans) = 0;

	virtual void postTransition(Transition& trans) = 0;
	virtual void fireTransition(Transition& trans) = 0;

	virtual void update() = 0;

	virtual void restart() = 0;
};

/// ====================================================================================================================
/// ===	CLASS
/// ====================================================================================================================

/// \class	State_Machine
///	\brief	State machine implementation.
/// \date	17/04/2017
/// \author	nboutin & bpayen
template<UCHAR8 n_state, UCHAR8 n_transition>
class State_Machine: public I_State_Machine
{
public:
	/// ============================================================================================================
	/// ===	PUBLIC DECLARATIONS
	/// ============================================================================================================

	State_Machine(State& start, const bool is_transition_true_used = false) :
			i_state_add(0), i_trans_add(0), p_state_start(&start), p_state_current(&start)

	{
		if (is_transition_true_used == true)
		{
			i_trans_add = 1; /// id 0 reserved for transition_true, highest priority
		}

		memset(pt_state_dest, 0x00, sizeof(State*) * n_state * n_transition);
	}

	/// \brief		State_Machine set transition priority
	/// 			First transition set will have the highest priority.
	/// \warning	Should be used before add ad it will also set a priority.
	/// \param		[in]Transition: Transition to set priority.
	bool setTransitionPriority(Transition& trans)
	{
		return generateId(trans);
	}

	/// \brief		Define relation between states and a transition.
	/// \warning	Transition priority is set in the order of the first call in add.
	///	\see		setTransitionPriority()
	///	\param		[in]State: Source state from which "trans" come from.
	/// \param		[in]State: Desination state to which "trans" go to.
	/// \param		[in]Transition: Directionnal link from "src" to "dst".
	virtual bool add(State& src, State& dst, Transition& trans)
	{
		bool b_result = true;

		b_result &= generateId(src);
		b_result &= generateId(dst);
		b_result &= generateId(trans);

		if (b_result == true)
		{
			pt_state_dest[src.getId()][trans.getId()] = &dst;
			return true;
		}
		else
		{
			return false;
		}
	}

	virtual bool remove(Transition& trans)
	{
		if (trans.getId() < n_transition)
		{
			for (UCHAR8 s = 0; s < n_state; s++)
			{
				pt_state_dest[s][trans.getId()] = NULL;
			}
			return true;
		}
		else
		{
			return false;
		}
	}

	/// \brief		Post a transition and immmediatly compute its effects on state machine
	///				according to current_state and transiton table.
	/// \warning	Must not be called in OnEnter and in OnExit State define functions.
	virtual void fireTransition(Transition& trans)
	{
		helper.setFlag(trans.getId());
		update(trans.getId());
	}

	/// \brief	Post a transition to the state_machine but does not compute next state.
	/// \param	[in]Transition: Transition to post.
	virtual void postTransition(Transition& trans)
	{
		helper.setFlag(trans.getId());
	}

	/// \brief	Compute next state according to posted transition and current state.
	///			Should be call periodically.
	virtual void update()
	{
		/// Loop on flags from the highest priority to the lowest
		UCHAR8 trans_id = helper.getHighestPriorityTransition(0, n_transition);

		while (trans_id < n_transition)
		{
			if (update(trans_id) == true)
			{
				/// Move to a new state so check Transition priority from beginning
				trans_id = helper.getHighestPriorityTransition(0, n_transition);
			}
			else
			{
				/// Search for next highest transition
				trans_id = helper.getHighestPriorityTransition(++trans_id, n_transition);
			}
		}
	}

	virtual void restart()
	{
		clearAllTransition();
		p_state_current = p_state_start;
	}

	void clearAllTransition()
	{
		helper.clearAllTransition();
	}

private:
	/// ============================================================================================================
	/// ===	PRIVATE DECLARATIONS
	/// ============================================================================================================

	bool update(const UCHAR8 trans_id)
	{
		UCHAR8 s = p_state_current->getId();
		UCHAR8 t = trans_id;

		if (pt_state_dest[s][t] != NULL)
		{
			/// On exit for current_state
			p_state_current->onExit();

			/// On transition
			/// if (trans.Execute() == false) return false;

			/// On enter for new state
			if (pt_state_dest[s][t]->onEnter() == false) return false;

			/// Save new current state
			p_state_current = pt_state_dest[s][t];

			pt_state_dest[s][t]->inState();

			helper.resetFlag(trans_id);

			return true;
		}

		return false;
	}

	bool generateId(State& state)
	{
		if (state.getId() == State::ID_DEFAULT)
		{
			if (i_state_add < n_state)
			{
				state.setId(i_state_add++);
			}
			else
			{
				return false;
			}
		}
		return true;
	}

	bool generateId(Transition& trans)
	{
		if (trans.getId() == Transition::ID_DEFAULT)
		{
			if (i_trans_add < n_transition)
			{
				trans.setId(i_trans_add++);
			}
			else
			{
				return false;
			}
		}
		return true;
	}

	/// ============================================================================================================
	/// ===	PRIVATE ATTRIBUTS
	/// ============================================================================================================

	State_Machine_Helper helper;

	UCHAR8 i_state_add;
	UCHAR8 i_trans_add;
	State* p_state_start;

	State* p_state_current;

	State* pt_state_dest[n_state][n_transition];

#ifdef TEST_INTEGR
	friend class ti_state_machine;
#endif
};

}	/// Namespace util

//#include "state_machine.tpp"

#endif	/// STATE_MACHINE_H_/// ====================================================================================================================/// ===	END OF FILE
/// ====================================================================================================================
