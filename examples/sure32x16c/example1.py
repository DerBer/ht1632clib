#!/usr/bin/env python

# Simple example for SURE electronics 32x16 bicolor led dot matrix.
# All led's will be switched on in red, then green, then orange and
# finally turned off (black that is).

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

print "all led's in red"
h.box(0, 0, WIDTH - 1, HEIGHT - 1, RED)
h.sendframe()

print "sleeping a while"
time.sleep(3)

print "all led's in green"
h.box(0, 0, WIDTH - 1, HEIGHT - 1, GREEN)
h.sendframe()

print "sleeping a while"
time.sleep(3)

print "all led's in orange"
h.box(0, 0, WIDTH - 1, HEIGHT - 1, ORANGE)
h.sendframe()

print "sleeping a while"
time.sleep(3)

print "all led's in black and end"
h.box(0, 0, WIDTH - 1, HEIGHT - 1, BLACK)
h.sendframe()

h.close()
print "done."
