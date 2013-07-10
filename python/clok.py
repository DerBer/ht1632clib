#!/usr/bin/env python

from ht1632c import HT1632C
from rotenc import RotEnc
from time import *
import signal
import sys

if __name__ == "__main__":
	# init display
	disp = HT1632C()
	disp.pwm(8)
	
	# init rotary encoder
	def cb(value):
		print("cb", value)
	rotenc = RotEnc(3, 4, 2, cb)
	
	# termination functions
	def stop(signal, stack):
		raise SystemExit('Exiting')
	signal.signal(signal.SIGTERM, stop)
	signal.signal(signal.SIGINT, stop)
	
	# display update
	def update():
		#print("update")
		disp.clear()
		t = localtime()
		s = strftime("%H:%M:%S")
		disp.putstr(-1, 0, strftime("%H", t), disp.font7x8, 1)
		disp.putstr(16, 0, strftime("%M", t), disp.font7x8, 1)
		disp.putstr(33, 0, strftime("%S", t), disp.font7x8, 1)
		disp.sendframe()
	
	try:
		while True:
			update()
			#t = time.localtime()
			sleep(1.0)
	except SystemExit as e:
		print(e.code)
	
	# turn off display
	disp.clear()
	disp.sendframe()
	
	print("Done.")
	sys.exit(0)
