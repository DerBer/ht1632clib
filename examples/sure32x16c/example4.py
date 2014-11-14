#!/usr/bin/env python

# Simple example for SURE electronics 32x16 bicolor led dot matrix.
# Will draw a green square and put two smaller red and filled
# squares inside it, wait a moment, the turn all off again.

import time
import ht1632c
import rotenc

def rtcallback(value):
	print "rotenc: %d\n" % value

NUM_PANELS = 3
PANEL_ROTATION = 0
WIDTH = NUM_PANELS * 32
HEIGHT = 16

ROTENC_PIN_0 = 3
ROTENC_PIN_1 = 4
ROTENC_PIN_BTN = 2

BLACK       = 0
GREEN       = 1
RED         =  2
ORANGE      = 3
TRANSPARENT = 0xff

print "init rotenc"
r=rotenc.RotEnc(ROTENC_PIN_0, ROTENC_PIN_1, ROTENC_PIN_BTN, rtcallback)

print "init ht1632c"
h=ht1632c.HT1632C(NUM_PANELS, PANEL_ROTATION)

h.pwm(7)

h.clear()
h.line(8, 0, 8, HEIGHT-1, GREEN)
h.line(8, 0, 23, 0, GREEN)
h.line(23, 0, 23, HEIGHT-1, GREEN)
h.line(8, HEIGHT-1, 23, HEIGHT-1, GREEN)

h.box(9, 1, 15, 7, RED)
h.box(16, 8, 22, 14, RED)

h.sendframe()

time.sleep(5)

print "all led's in black and end"
h.box(0, 0, WIDTH - 1, HEIGHT - 1, BLACK)
h.sendframe()

h.close()
print "done."
