#include "rotenc.h"

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <wiringPi.h>

// Number of WiringPi lock used
#define LOCK_ID 2

static int rotenc_pin_enc0 = 0;
static int rotenc_pin_enc1 = 0;
static int rotenc_pin_btn = 0;
static rotenc_callback_t rotenc_callback = 0;
static int rotenc_value = 0;

void rotenc_decode(int code)
{
	static int state = 0;
	if (state == 0) {
		if (code == 0)
			state = 1;
		else if (code == 1)
			state = -1;
	} else if (state > 0) {
		if ((code == state) && (++state >= 4)) {
			rotenc_value = 1;
			piUnlock(LOCK_ID);
			state = 0;
		}
	} else { // (state < 0)
		if (((code ^ 2) == -state) && (--state <= 4)) {
			rotenc_value = -1;
			piUnlock(LOCK_ID);
			state = 0;
		}
	}
}

void rotenc_isr_enc0()
{
	rotenc_decode(digitalRead(rotenc_pin_enc0) << 1);
}

void rotenc_isr_enc1()
{
	rotenc_decode((digitalRead(rotenc_pin_enc1) << 1) | 1);
}

void rotenc_isr_btn()
{
	rotenc_value = 0;
	piUnlock(LOCK_ID);
}

PI_THREAD(cbThread)
{
	piHiPri(10);
	for (;;) {
		piLock(LOCK_ID);
		rotenc_callback(rotenc_value);
	}
}

int rotenc_init(int pinEnc0, int pinEnc1, int pinBtn, rotenc_callback_t callback)
{
	rotenc_pin_enc0 = pinEnc0;
	rotenc_pin_enc1 = pinEnc1;
	rotenc_pin_btn = pinBtn;
	rotenc_callback = callback;
	
	// init WiringPi
	if (wiringPiSetup() == -1) {
		printf( "WiringPi Setup Failed: %s\n", strerror(errno));
		return 1;
	}

	// configure pins
	pinMode(pinEnc0, INPUT);
	pinMode(pinEnc1, INPUT);
	pinMode(pinBtn, INPUT);
	pullUpDnControl(pinEnc0, PUD_UP);
	pullUpDnControl(pinEnc1, PUD_UP);
	pullUpDnControl(pinBtn, PUD_UP);
	wiringPiISR(pinEnc0, INT_EDGE_BOTH, &rotenc_isr_enc0);
	wiringPiISR(pinEnc1, INT_EDGE_BOTH, &rotenc_isr_enc1);
	wiringPiISR(pinBtn, INT_EDGE_RISING, &rotenc_isr_btn);
	
	// start handler thread
	if (piThreadCreate(cbThread) != 0) {
		printf( "Could not create rotary encoder handler thread\n");
		return 1;
	}
	
	return 0;
}
