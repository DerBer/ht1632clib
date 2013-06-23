#include "rotenc.h"

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <wiringPi.h>

int rotenc_pin0 = 0;
int rotenc_pin1 = 0;
rotenc_callback_t rotenc_callback = 0;

void rotenc_decode(int code)
{
// 	printf("code: %d\n", code);
	static int state = 0;
	if (state == 0) {
		if (code == 0)
			state = 1;
		else if (code == 1)
			state = -1;
	} else if (state > 0) {
		if ((code == state) && (++state >= 4)) {
			rotenc_callback(1);
			state = 0;
		}
	} else { // (state < 0)
		if (((code ^ 2) == -state) && (--state <= 4)) {
			rotenc_callback(-1);
			state = 0;
		}
	}
// 	printf("state: %d\n", state);
}

void rotenc_isr0()
{
	rotenc_decode(digitalRead(rotenc_pin0) << 1);
}
void rotenc_isr1()
{
	rotenc_decode((digitalRead(rotenc_pin1) << 1) | 1);
}

int rotenc_init(int pin0, int pin1, rotenc_callback_t callback)
{
	rotenc_pin0 = pin0;
	rotenc_pin1 = pin1;
	rotenc_callback = callback;
	
	// init WiringPi
	if (wiringPiSetup() == -1) {
		printf( "WiringPi Setup Failed: %s\n", strerror(errno));
		return 1;
	}

	// configure pins
	pinMode(pin0, INPUT);
	pinMode(pin1, INPUT);
	pullUpDnControl(pin0, PUD_UP);
	pullUpDnControl(pin1, PUD_UP);
	wiringPiISR(pin0, INT_EDGE_BOTH, &rotenc_isr0);
	wiringPiISR(pin1, INT_EDGE_BOTH, &rotenc_isr1);

	return 0;
}
