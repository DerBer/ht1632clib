/*
 * Simple example for SURE electronics 32x16 bicolor led dot matrix.
 * Will scroll the text "Hello there" from left to right, 3 times
 * each time in another color. For font selection have a look at
 * the predefined ones inside fonts.h of the main directory.
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

	int color = GREEN;
	for(int i=0;i<480;i++) {
		int j = (i + 1) % 160;
		if(j == 0) color ++;
		ht1632c_clear();
		ht1632c_putstr(32-j, 0, "Hello there", &font_12x16, color, TRANSPARENT);
		ht1632c_sendframe();
		usleep(50000);
	}

	printf("all led's in black and end\n");
	ht1632c_box(0, 0, WIDTH - 1, HEIGHT - 1, BLACK);
	ht1632c_sendframe();

	ht1632c_close();
	printf("done.\n");
}
