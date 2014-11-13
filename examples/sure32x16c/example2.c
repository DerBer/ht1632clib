/*
 * Simple example for SURE electronics 32x16 bicolor led dot matrix.
 * All led's will be switched on in different colors depending of
 * the current x/y position and loop counter i, hence an animation
 * in all 3 colors that runs over the whole display.
 * Finally turn off again all (black that is).
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

	for(int i=0;i<100;i++) {
		for (int x = 0; x < WIDTH; ++x) {
			for (int y = 0; y < HEIGHT; ++y) {
				ht1632c_plot(x, y, (i + x + y) & ORANGE);
			}
		}
		ht1632c_sendframe();

		usleep(100000);
	}

	printf("all led's in black and end\n");
 	ht1632c_box(0, 0, WIDTH - 1, HEIGHT - 1, BLACK);
	ht1632c_sendframe();

	ht1632c_close();
	printf("done.\n");
}
