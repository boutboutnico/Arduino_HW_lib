///
/// State Machine Transition model.
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
/// \file	transition.h
/// \brief	Transition model.
/// \date	07/04/2014
/// \author	nboutin
///

#ifndef TRANSITION_H_
#define TRANSITION_H_

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

/// \class	Transition
///	\brief	Model a transition in State_Machine.
/// \date	17/04/2014
/// \author	nboutin & bpayen
class Transition
{
		/// Only State_Machine can change a Transition id.
		template<UCHAR8 n_state, UCHAR8 n_transition> friend class State_Machine;

	public:
		/// ============================================================================================================
		/// ===	PUBLIC CONSTANTS
		/// ============================================================================================================

		static const UCHAR8 ID_DEFAULT = 0xFF;

		/// ============================================================================================================
		/// ===	PUBLIC DECLARATIONS
		/// ============================================================================================================

		Transition()
				: id(ID_DEFAULT)
		{

		}

		UCHAR8 getId() const
		{
			return id;
		}

	protected:
		/// ============================================================================================================
		/// ===	PROTECTED ATTRIBUTS
		/// ============================================================================================================

		UCHAR8 id;	//!< Transition identifiant and priority.

	private:
		/// ============================================================================================================
		/// ===	PRIVATE DECLARATIONS
		/// ============================================================================================================

		void setId(const UCHAR8 iu8_id)
		{
			id = iu8_id;
		}
};

/// ====================================================================================================================
/// ===	CLASS
/// ====================================================================================================================

/// \class	Transition_True
///	\brief	Model an always true transition in State_Machine.
/// \date	17/04/2014
/// \author	nboutin & bpayen
class Transition_True: public Transition
{
	public:
		/// ============================================================================================================
		/// ===	PUBLIC CONSTANTS
		/// ============================================================================================================

		static const ULONG32 BIT_DEFAULT = 0;

		/// ============================================================================================================
		/// ===	PUBLIC DECLARATIONS
		/// ============================================================================================================

		static Transition_True& get()
		{
			static Transition_True inst;
			return inst;
		}

	private:
		/// ============================================================================================================
		/// ===	PRIVATE DECLARATIONS
		/// ============================================================================================================

		/// \brief	Force Transition_True to be at id = BIT_DEFAULT and so detected by State_Machine.
		Transition_True()
				: Transition()
		{
			id = BIT_DEFAULT;
		}
};

}

#endif	/// TRANSITION_H_
/// ====================================================================================================================
/// ===	END OF FILE
/// ====================================================================================================================
