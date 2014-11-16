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
#include "queue.h"
#include "semphr.h"

#include "Arduino.h"
//#include "streaming.h"

/* this is from avr/time.h, but it is not released into the main stream currently */
#include "time.h"

/* serial interface include file. */
#include "serial.h"

#include "tsk_test.h"

/*-----------------------------------------------------------*/
/* Optionally, create reference to the handle for the serial port. */
extern xComPortHandle xSerialPort;

/* Main program loop */
int main(void) __attribute__ ((OS_main));

int main(void)
{
	// turn on the serial port for debugging or for other USART reasons.
	//  serial port: WantedBaud, TxQueueLength, RxQueueLength (8n1)
	xSerialPort = xSerialPortInitMinimal(USART0, 115200, portSERIAL_BUFFER_TX,
	portSERIAL_BUFFER_RX);

	avrSerialxPrint_P(&xSerialPort, PSTR("Hello World!\n"));

	TSK_RX tsk_test;
	TSK_Test1 tsk_test1;

	avrSerialxPrintf_P(&xSerialPort, PSTR("Free Heap Size: %u\r\n"), xPortGetFreeHeapSize());

	vTaskStartScheduler();

	// Doh, so we're dead...
	avrSerialxPrint_P(&xSerialPort, PSTR("\r\n\n\nGoodbye... no space for idle task!\r\n"));
}
/*-----------------------------------------------------------*/
