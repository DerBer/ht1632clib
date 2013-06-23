#include <inttypes.h>

typedef struct
{
	const uint8_t width;
	const uint8_t height;
	const uint8_t map_start;
	const uint8_t map_end;
	const uint16_t* data;
} FontInfo;

extern const FontInfo font_6x8;
// extern const FontInfo font_3x5;