#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

// #include "wiringPi.h"

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
	
// 	printf("set pwm\n");
	ht1632c_pwm(7);

// 	for (int i = 0; i < 2400; ++i) {
// 		printf("%d\n", i);
// 		
// // 		ht1632c_clear();
// // 		ht1632c_plot(0 + 24, i, 1);
// 		ht1632c_plot(i, i / 2, 1);
// // 		_setbit(i + 10);
// 		ht1632c_sendframe();
// 		usleep(100000);
// 	}
// 	int i = 0;
// 	while (1) {
// 		i = (i + 1) % 64;
// 		ht1632c_clear();
// // 		ht1632c_clip(1, 1, 60, 7);
// 		ht1632c_putstr(32-i, 0, "0123456789", &font_7x8_num, 3, TRANSPARENT);
// 		ht1632c_sendframe();
// 		usleep(50000);
// 	}

// 	ht1632c_putstr(0, 0, "0123", &font_7x8_num, 1, TRANSPARENT);
// 	ht1632c_sendframe();
// 	
// 	usleep(1000000);
// 	while (1) {
// 		ht1632c_game(0, 0, ht1632c_width() - 1, ht1632c_height() - 1, 1);
// 		ht1632c_sendframe();
// 		usleep(10000);
// 	}

// 	ht1632c_box(0, 0, 63, 15, 3);
// 	ht1632c_sendframe();
// 	while (1) usleep(1000000);
	
// 	int i = 0;
// 	while (1) {
// 	// 	printf("draw\n");
// 		for (int x = 0; x < WIDTH; ++x) {
// 			for (int y = 0; y < HEIGHT; ++y) {
// 				ht1632c_plot(x, y, (i + x + y) & ORANGE);
// 			}
// 		}
// 		
// // 		ht1632c_line(i % 32 - 1, 4, i % 32 - 1, 11, BLACK);
// // 		ht1632c_putchar(i % 64, 4, '0' + i % 10, &font_6x8, GREEN);
// 	// 	ht1632c_putchar(7, 0, '1', &font_6x8, 1);
// 	// 	ht1632c_putchar(14, 0, '2', &font_6x8, 1);
// 	// 	ht1632c_plot(0, 0, 2);
// 	// 	ht1632c_plot(3, 3, 2);
// 	// 	ht1632c_plot(16, 15, 3);
// // 	ht1632c_plot(i % 64, 3, ((i / 64) + 1) & ORANGE);
// 		
// 	// 	printf("sendframe\n");
// 		ht1632c_sendframe();
// 		
// 		i++;
// 		usleep(100000);
// 	}
	
	ht1632c_line(0, 0, WIDTH - 1, HEIGHT - 1, RED);
	ht1632c_line(0, HEIGHT - 1, WIDTH - 1, 0, RED);
// 	ht1632c_box(0, 0, WIDTH - 1, HEIGHT - 1, ORANGE);
	ht1632c_sendframe();
	
	ht1632c_close();
	printf("done.\n");
}
