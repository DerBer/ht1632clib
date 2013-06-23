#!/usr/bin/env python

from ht1632c import HT1632C

disp = HT1632C()
disp.pwm(8)

#disp.plot(0,0,1)
#disp.sendframe()

#print(disp.font6x8)
disp.putstr(-1, 0, '23', disp.font6x8, 1)
disp.putchar(12, 0, '4', disp.font6x8, 1)
disp.putchar(18, 0, '5', disp.font6x8, 1)
disp.box(0, 8, 23, 8, 1)
#disp.line(0, 8, 23, 15, 0)
#disp.line(0, 15, 23, 8, 0)
disp.sendframe()
