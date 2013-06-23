#ifndef HT1632C_H
#define HT1632C_H

#include <inttypes.h>

#include "fonts.h"

//
// constants
//

#define BLACK        0
#define GREEN        1
#define RED          2
#define ORANGE       3

//
// public functions
//

int ht1632c_init();
void ht1632c_pwm(const uint8_t value);
/// sends frame buffer to display; required to bring any drawing operations to the display
void ht1632c_sendframe();
/// clears the whole frame
void ht1632c_clear();
/// put a single pixel in the coordinates x, y
void ht1632c_plot(const int x, const int y, const uint8_t color);
///
void ht1632c_line(const int x0, const int y0, const int x1, const int y1, const uint8_t color);
///
int ht1632c_putchar(const int x, const int y, const char c, const FontInfo* font, const uint8_t color);

// void _setbit(int p); // F-IXME

#endif
