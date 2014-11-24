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

#include "signal_proccessing/filter.hpp"

/// === STATIC IMPORT	============================================================================

extern xComPortHandle xSerialPort;

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

static const uint8_t pin_dcf_in = 2;
static const uint8_t pin_dcf_filtered = 3;
static const uint8_t pin_dcf_filtered_2 = 4;

/// ------------------------------------------------------------------------------------------------

void MsTimer_callback()
{
	const uint8_t value = digitalRead(pin_dcf_in);

	///
	/// Low Pass Filter
	///
	uint8_t filtered = filter::low_pass_filter(value);

	digitalWrite(pin_dcf_filtered, filtered);

	///
	/// SMA
	///
//	static const uint8_t N = 50;
//	static uint32_t mem[N];
//	static uint32_t sma = 0;
////	static uint32_t i = 0;
//
//	filter::simple_moving_average(value * offset, mem, N, sma);
//
//	static bool out = false;
//	filter::hysteresis(sma, offset / 2, out);
//
////	filtered_sma = out ? offset : 0;
//
//	digitalWrite(pin_dcf_filtered_2, out);

	///
	/// EMA
	///
	static const uint32_t offset = 10000;
	static const uint16_t alpha = 95; /// 196=50ms, 95 = 75ms
	static uint32_t ema = 0;
	static bool state = false;

	ema = filter::exponential_moving_average(value * offset, ema, alpha);

	if (filter::hysteresis(ema, offset / 2, state) == true)
	{
		ema = state ? offset : 0;
	}

	digitalWrite(pin_dcf_filtered_2, state);
}

/// ------------------------------------------------------------------------------------------------

void TSK_RX::run()
{
	static const TickType_t delay = 500;

/// PORTB4 output
	bitSet(DDRB, DDB4);
	bitClear(PORTB, PORTB4);

	/// PORTB5 input and Pull-up ON
//	bitClear(DDRB, DDB0);
//	bitSet(PORTB, PORTB0);

	pinMode(pin_dcf_in, INPUT);
	pinMode(pin_dcf_filtered, OUTPUT);
	pinMode(pin_dcf_filtered_2, OUTPUT);

	timer.start();

	MsTimer2::set(1, MsTimer_callback);
	MsTimer2::start();

//	xSerialxPrintf_P(&xSerialPort, PSTR("bool:%d\n"), sizeof(bool));
//	xSerialxPrintf_P(&xSerialPort, PSTR("uint32_t:%d\n"), sizeof(uint32_t));
//
//	xSerialxPrintf_P(&xSerialPort, PSTR("int:%d\n"), sizeof(int));
//	xSerialxPrintf_P(&xSerialPort, PSTR("u int:%d\n"), sizeof(unsigned int));
//	xSerialxPrintf_P(&xSerialPort, PSTR("ul int:%d\n"), sizeof(unsigned long int));

	for (;;)
	{
		static bool out = false;

		static const uint8_t val_max = 10;

		OS::delayUntil(delay);

		for (uint8_t i = 0; i < val_max; i++)
		{
//			out = filter::hysteresis(i, out, val_max / 2);

//			xSerialxPrintf_P(&xSerialPort, PSTR("i:%d\t out:%d\n"), i, out);

			OS::delayUntil(delay);
		}

		for (uint8_t i = val_max; i > 0; i--)
		{
//			out = filter::hysteresis(i, out, val_max / 2);

//			xSerialxPrintf_P(&xSerialPort, PSTR("i:%d\t out:%d\n"), i, out);

			OS::delayUntil(delay);
		}

//		uint8_t val = 0;
//
//		{
//			val = filter::test<uint8_t>();
//			xSerialxPrintf_P(&xSerialPort, PSTR("Count_1: %d\n"), val);
//		}
//
//		{
//			val = filter::test<uint8_t>();
//			xSerialxPrintf_P(&xSerialPort, PSTR("Count_2: %d\n"), val);
//		}

//		xSerialxPrintf_P(&xSerialPort, PSTR("Count: %d\t%d\n"), count_high_, count_low_);
//		count_ = 0;
//		bitClear(PORTB, PORTB4);

//		xSerialxPrintf_P(&xSerialPort, PSTR("AnalogRead: %d\n"), digitalRead(dcf77_analog_sample_pin));

//		OS::delayUntil(delay);

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
//	const uint8_t value = digitalRead(pin_dcf_in);
//
//	uint8_t filtered = filter::low_pass_filter(value);
//
//	digitalWrite(pin_dcf_filtered, filtered);

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
