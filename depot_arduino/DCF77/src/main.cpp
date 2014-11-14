////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////    main.c
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include <avr/io.h>
#include <avr/interrupt.h>

/* Scheduler include files. */
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
//#include "queue.h"
//#include "semphr.h"

/* this is from avr/time.h, but it is not released into the main stream currently */
#include "time.h"

/* serial interface include file. */
#include "serial.h"

#include "tsk_rx.h"

/*-----------------------------------------------------------*/
/* Optionally, create reference to the handle for the serial port. */
extern xComPortHandle xSerialPort;

//TimerHandle_t xTimer;
//
//void vTimerCallBack(TimerHandle_t pxTimer)
//{
//	static bool b_on = true;
//
//	if(b_on)
//	{
//		b_on = false;
//		bitSet(PORTB, PORTB5);
//	}
//	else
//	{
//		b_on = true;
//		bitClear(PORTB, PORTB5);
//	}
//
//}

/* Main program loop */
int main(void) __attribute__ ((OS_main));

int main(void)
{
	/// turn on the serial port for debugging or for other USART reasons.
	/// serial port: WantedBaud, TxQueueLength, RxQueueLength (8n1)
	xSerialPort = xSerialPortInitMinimal(USART0, 115200, portSERIAL_BUFFER_TX,
	portSERIAL_BUFFER_RX);

//	DDRB |= _BV(DDB4);
//	xTimer = xTimerCreate("T", OS::ms_to_ticks(1000), pdTRUE, 0, vTimerCallBack);
//	xTimerStart(xTimer, 0);

	avrSerialxPrint_P(&xSerialPort, PSTR("Creating task...\n"));

	TSK_RX tsk_test;

	avrSerialxPrintf_P(&xSerialPort, PSTR("Free Heap Size: %u\n"), xPortGetFreeHeapSize());
	avrSerialxPrintf_P(&xSerialPort, PSTR("Running...\n"), xPortGetFreeHeapSize());

	vTaskStartScheduler();

	// Doh, so we're dead...
	avrSerialxPrint_P(&xSerialPort, PSTR("\r\n\n\nGoodbye... no space for idle task!\r\n"));
}
/*-----------------------------------------------------------*/
