#!/usr/bin/env python

from ht1632c import HT1632C
from rotenc import RotEnc
#from threading import Timer
from time import *
#from daemon import createDaemon
import signal
import sys
#import daemon
##import lockfile.pidlockfile
#from lockfile.pidlockfile import PIDLockFile

#import multiprocessing

#stop_event = multiprocessing.Event()

#context = daemon.DaemonContext(
	##pidfile = lockfile.FileLock("/var/run/clok.pid")
	#pidfile = PIDLockFile("/var/run/clok.pid", None)
#)

#def stop():
	##raise SystemExit('Exiting')
	#stop_event.set()

#context.signal_map = {
	#signal.SIGTERM: stop,
	##signal.SIGHUP: 'terminate',
	##signal.SIGUSR1: reload_program_config,
#}

if __name__ == "__main__":
#with context:
	# run as daemon
	#createDaemon()
	
	# init display
	disp = HT1632C()
	disp.pwm(8)

	#disp.plot(0,0,1)
	#disp.sendframe()

	#print(disp.font6x8)
	#disp.putstr(-1, 0, '23', disp.font6x8, 1)
	#disp.putchar(12, 0, '4', disp.font6x8, 1)
	#disp.putchar(18, 0, '5', disp.font6x8, 1)
	#disp.box(0, 8, 23, 8, 1)
	#disp.line(0, 8, 23, 15, 0)
	#disp.line(0, 15, 23, 8, 0)
	#disp.sendframe()

	def cb(value):
		print("cb", value)

	rotenc = RotEnc(3, 4, 2, cb)

	def update():
		#print("update")
		disp.clear()
		t = localtime()
		s = strftime("%H:%M:%S")
		disp.putstr(-1, 0, strftime("%H", t), disp.font7x8, 1)
		disp.putstr(16, 0, strftime("%M", t), disp.font7x8, 1)
		disp.putstr(33, 0, strftime("%S", t), disp.font7x8, 1)
		disp.sendframe()

	#Timer(1.0, update).start()
	
	def stop(signal, stack):
		raise SystemExit('Exiting')
	signal.signal(signal.SIGTERM, stop)
	signal.signal(signal.SIGINT, stop)
	##signal.signal(signal.SIGHUP, stop)
	
	try:
		while True:
		#while not stop_event.is_set():
			update()
			#t = time.localtime()
			sleep(1.0)
	except SystemExit as e:
		print(e.code)
	
	print("Done.")
	sys.exit(0)
