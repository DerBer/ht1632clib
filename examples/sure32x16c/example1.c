/*
 * Simple example for SURE electronics 32x16 bicolor led dot matrix.
 * All led's will be switched on in red, then green, then orange and
 * finally turned off (black that is).
 */

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#include "ht1632c.h"
#include "rotenc.h"

#define NUM_PANELS 3
#define PANEL_ROTATION 0
#define WIDTH (NUM_PANELS * 32)
#define HEIGHT 16

#define ROTENC_PIN_0 3
#define ROTENC_PIN_1 4
#define ROTENC_PIN_BTN 2

void rotenc(int value)
{
	printf("rotenc: %d\n", value);
}

int main(void)
{
	printf("init rotenc\n");
	rotenc_init(ROTENC_PIN_0, ROTENC_PIN_1, ROTENC_PIN_BTN, &rotenc);
	
	printf("init ht1632c\n");
	ht1632c_init(NUM_PANELS, PANEL_ROTATION);
	
	ht1632c_pwm(7);

	printf("all led's in red\n");
 	ht1632c_box(0, 0, WIDTH - 1, HEIGHT - 1, RED);
	ht1632c_sendframe();
	
	printf("sleeping a while\n");
	sleep(3);

	printf("all led's in green\n");
 	ht1632c_box(0, 0, WIDTH - 1, HEIGHT - 1, GREEN);
	ht1632c_sendframe();

	printf("sleeping a while\n");
	sleep(3);

	printf("all led's in orange\n");
 	ht1632c_box(0, 0, WIDTH - 1, HEIGHT - 1, ORANGE);
	ht1632c_sendframe();

	printf("sleeping a while\n");
	sleep(3);

	printf("all led's in black and end\n");
 	ht1632c_box(0, 0, WIDTH - 1, HEIGHT - 1, BLACK);
	ht1632c_sendframe();

	ht1632c_close();
	printf("done.\n");
}
