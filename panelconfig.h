// ht1632c panel configuration

// #define PANEL_32x16C /* preset for bi-color 32x16 panel */
#define PANEL_24x16  /* preset for monochrome 24x16 panel */

// Chained chip select mode.
// Define if chip select pins are connected directly to output pins.
// Don't define if chips are chained and connected using CLK/CS lines.
#ifdef PANEL_32x16C
	#define HT1632_CS_CHAINED
#endif
#ifdef PANEL_24x16
	#undef HT1632_CS_CHAINED
#endif

// chip select pins
#ifdef HT1632_CS_CHAINED
	#define HT1632_CLK  0           /* chip select clock pin */
	#define HT1632_CS   1           /* chip select data pin */
#else
	#define HT1632_CS   0           /* first chip select pin; */
	                                /* successive pin numbers are used for additional chips */
#endif

// panel parameters
#ifdef PANEL_32x16C
	#define NUM_PANELS 2            /* number of panels */
	#define CHIPS_PER_PANEL 4       /* ht1632c chips per panel */
	#define WIDTH (32 * NUM_PANELS) /* display width (pixels) */
	#define HEIGHT 16               /* display height (pixels) */
	#define CHIP_WIDTH 16           /* chip width (pixels) */
	#define CHIP_HEIGHT 8           /* chip height (pixels) */
	#define COLORS 2                /* number of colors (1 or 2) */
#endif
#ifdef PANEL_24x16
	#define NUM_PANELS 1            /* number of panels */
	#define CHIPS_PER_PANEL 1       /* ht1632c chips per panel */
	#define WIDTH (24 * NUM_PANELS) /* display width (pixels) */
	#define HEIGHT 16               /* display height (pixels) */
	#define CHIP_WIDTH 24           /* chip width (pixels) */
	#define CHIP_HEIGHT 16          /* chip height (pixels) */
	#define COLORS 1                /* number of colors (1 or 2) */
#endif
