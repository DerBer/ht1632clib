#!/usr/bin/env python

from ht1632c import HT1632C

disp = HT1632C()
disp.pwm(8)

#disp.plot(0,0,1)
#disp.sendframe()

#print(disp.font6x8)
disp.putchar(-1, 0, '2', disp.font6x8, 1)
disp.putchar(5, 0, '3', disp.font6x8, 1)
disp.putchar(12, 0, '4', disp.font6x8, 1)
disp.putchar(18, 0, '5', disp.font6x8, 1)
disp.sendframe()
