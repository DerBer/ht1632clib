/*
 * Simple example for SURE electronics 32x16 bicolor led dot matrix.
 * Will draw a green square and put two smaller red and filled
 * squares inside it, wait a moment, the turn all off again.
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

	ht1632c_clear();
	ht1632c_line(8, 0, 8, HEIGHT-1, GREEN);
	ht1632c_line(8, 0, 23, 0, GREEN);
	ht1632c_line(23, 0, 23, HEIGHT-1, GREEN);
	ht1632c_line(8, HEIGHT-1, 23, HEIGHT-1, GREEN);

	ht1632c_box(9, 1, 15, 7, RED);
	ht1632c_box(16, 8, 22, 14, RED);

	ht1632c_sendframe();

	sleep(5);

	printf("all led's in black and end\n");
	ht1632c_box(0, 0, WIDTH - 1, HEIGHT - 1, BLACK);
	ht1632c_sendframe();

	ht1632c_close();
	printf("done.\n");
}
