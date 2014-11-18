/*
 * tsk_test.cpp
 *
 *  Created on: 31 mars 2014
 *      Author: Nico_user
 */

#include "tsk_rx.h"

/// === INCLUDES	================================================================================

#include "serial.h"
#include "Arduino.h"
#include "MsTimer2.h"

/// === STATIC IMPORT	============================================================================

xComPortHandle xSerialPort;

/// === STATIC DEFINITIONS	========================================================================

E_Bit_Type TSK_RX::e_bit_type = SYNCHRONIZATION;
uint8_t TSK_RX::count_high_ = 0;
uint8_t TSK_RX::count_low_ = 0;

/// === PUBLIC DEFINITIONS	========================================================================

TSK_RX::TSK_RX()
		: 	Task("TSK_RX", STACK_SIZE, STACK_PRIORITY),
			timer("TIM_RX", TIMER_DURATION, true, TSK_RX::callback)
{
}

/// ------------------------------------------------------------------------------------------------

const uint8_t dcf77_analog_sample_pin = A0;

const uint8_t filtered_dcf77_pin = 2;

void low_pass_filter()
{
    // http://en.wikipedia.org/wiki/Low-pass_filter#Continuous-time_low-pass_filters

    // I will use fixed point arithmetics with 5 decimals
    const uint16_t decimal_offset = 10000;
    static uint32_t smoothed = 0*decimal_offset;

    const uint32_t input = digitalRead(dcf77_analog_sample_pin) * decimal_offset;
//    const uint32_t input = analogRead(dcf77_analog_sample_pin)>200 ? decimal_offset : 0;

    // compute N such that the smoothed signal will always reach 50% of
    // the input after at most 50 samples (=50ms).
    // N = 1 / (1- 2^-(1/50)) = 72.635907286
    const uint16_t N = 72;
    smoothed = ((N-1) * smoothed + input) / N;

    // introduce some hysteresis
    static uint8_t square_wave_output = 0;

    if ((square_wave_output == 0) == (smoothed >= decimal_offset/2)) {
        // smoothed value more >= 50% away from output
        // ==> switch output
        square_wave_output = 1-square_wave_output;
        // ==> max the smoothed value in order to introduce some
        //     hysteresis, this also ensures that there is no
        //     "infinite memory"
        smoothed = square_wave_output? decimal_offset: 0;
    }

    digitalWrite(filtered_dcf77_pin, square_wave_output);
}

void TSK_RX::run()
{
	static const TickType_t delay = 10;

//	DDRB |= _BV(DDB4);
//	DDRB |= _BV(DDB5);

/// PORTB4 output
	bitSet(DDRB, DDB4);
	bitClear(PORTB, PORTB4);

	/// PORTB5 input and Pull-up ON
//	bitClear(DDRB, DDB0);
//	bitSet(PORTB, PORTB0);
//	bitClear(PORTB, PORTB0);

	timer.start();
//	volatile uint8_t read = 0;

	pinMode(dcf77_analog_sample_pin, INPUT);

	pinMode(filtered_dcf77_pin, OUTPUT);

	MsTimer2::set(1, low_pass_filter);
	MsTimer2::start();

	for (;;)
	{

//		xSerialxPrintf_P(&xSerialPort, PSTR("Count: %d\t%d\n"), count_high_, count_low_);
//		count_ = 0;
//		bitClear(PORTB, PORTB4);

//		xSerialxPrintf_P(&xSerialPort, PSTR("AnalogRead: %d\n"), digitalRead(dcf77_analog_sample_pin));

		OS::delayUntil(delay);

//		read = bitRead(PINB, PINB5);
//		xSerialxPrintf_P(&xSerialPort, PSTR("read: %d\n"), read);
//
//		bitSet(PORTB, PORTB4);
//		OS::delayUntil(delay);
//
//
//		read = bitRead(PINB, PINB5);
//		xSerialxPrintf_P(&xSerialPort, PSTR("read: %d\n"), read);
//
//		bitClear(PORTB, PORTB4);
//		OS::delayUntil(delay);
	}
}

void TSK_RX::callback(TimerHandle_t pxTimer)
{
//	analogRead()

//	static uint8_t count_high = 0;
//	static uint8_t count_low = 0;
//	static bool copied = false;
//
//	volatile uint8_t read = bitRead(PINB, PINB0);
//
//	if (read)
//	{
//		count_high++;
//
//		copied = false;
//
//		bitClear(PORTB, PORTB4);
//	}
//	else
//	{
//		bitSet(PORTB, PORTB4);
//
//		if (copied == false)
//		{
//			copied = true;
//			count_high_ = count_high;
//			count_low_ = count_low;
//
//			count_high = 0;
//			count_low = 0;
//		}
//
//		count_low++;
//	}

}

/// === END OF FILE	================================================================================
