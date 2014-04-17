///
/// State Machine helper to reduce code size from State Machine template.
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
/// \file	state_machine_helper.h
/// \brief	State machine helper.
/// \date	07/04/2014
/// \author	nboutin
///

namespace util
{

class State_Machine_Helper
{
public:
	/// ============================================================================================================
	/// ===	PUBLIC CONSTANTS
	/// ============================================================================================================

	static const ULONG32 FLAGS_DEFAULT = ((ULONG32) 1 << Transition_True::BIT_DEFAULT);

	/// ============================================================================================================
	/// ===	PUBLIC DECLARATIONS
	/// ============================================================================================================

	State_Machine_Helper() :
			flags(FLAGS_DEFAULT)
	{

	}

	UCHAR8 getHighestPriorityTransition(const UCHAR8 start_id, const UCHAR8 n_transition)
	{
		for (UCHAR8 i = start_id; i < n_transition; i++)
		{
			if (flags & (1 << i))
			{
				return i;
			}
		}
		return n_transition;
	}

	void clearAllTransition()
	{
		flags = FLAGS_DEFAULT;
	}

	void setFlag(const UCHAR8 trans_id)
	{
		flags |= 1 << trans_id;
	}

	void resetFlag(const UCHAR8 trans_id)
	{
		flags &= ~(1 << trans_id) | FLAGS_DEFAULT;
	}

private:
	/// ============================================================================================================
	/// ===	PRIVATE ATTRIBUTS
	/// ============================================================================================================

	ULONG32 flags;

};

}
