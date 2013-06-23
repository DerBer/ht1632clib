#include "ht1632c.h"
#include <stdio.h>
#include <unistd.h>

int main(void) {
	printf("init\n");
	ht1632c_init();
	
	printf("set pwm\n");
	ht1632c_pwm(8);

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
	ht1632c_putchar(0, 0, '0', &font_6x8, 1);
	ht1632c_sendframe();
	
// 	int i = 0;
// 	while (1) {
// 	// 	printf("draw\n");
// 		for (int x = 0; x < 64; ++x) {
// 			for (int y = 0; y < 16; ++y) {
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
	
// 	printf("done.\n");
}
