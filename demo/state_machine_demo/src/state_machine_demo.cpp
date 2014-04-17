///
/// This example code is in the public domain.
/// \file	lcd_i2c_demo.cpp
/// \brief	Demonstrates use of the LCD Library
/// \date	05/04/2014
/// \author	nboutin
///
/// Board	Arduino UNO R3
/// IDE		Eclipse Kepler
/// LCD I2C	PCM2004E6-2
/// Pin		Board	LCD
/// SDA_20	SDA 	(white) + resistance pull-up 2k
/// SCL_21	SCL 	(yellow) + resistance pull-up 2k
/// 5V		5V 		(red)
/// GND		GND		(black)
///

/// ------------------------------------------------------------------------------------------------
/// INCLUDES
/// ------------------------------------------------------------------------------------------------
#include "Arduino.h"

#include "state_machine.h"

/// ------------------------------------------------------------------------------------------------
/// NAMESPACE
/// ------------------------------------------------------------------------------------------------
using namespace util;

/// ------------------------------------------------------------------------------------------------
/// GLOBALE VARIABLES
/// ------------------------------------------------------------------------------------------------

int main()
{
	State s_on, s_off;
	Transition t_on, t_off;

	State_Machine<2,2> state_machine(s_off);

	state_machine.add(s_on, s_off, t_off);
	state_machine.add(s_off, s_on, t_on);


	state_machine.fireTransition(t_on);
	state_machine.fireTransition(t_off);
}

/// ------------------------------------------------------------------------------------------------
/// END OF FILE
/// ------------------------------------------------------------------------------------------------
