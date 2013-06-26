from ctypes import *
lib = cdll.LoadLibrary('../libht1632c.so')

from threading import *

CBFUNC = CFUNCTYPE(None, c_int)
lib.rotenc_init.argtypes = [c_int, c_int, CBFUNC]
lib.rotenc_init.restype = c_int

class RotEnc(object):
	#def getCallbackFunc(self):
		#print(self.callback)
			##self.callback(value)
		#return self.CBFUNC(cb)

	def __init__(self, pin0, pin1, callback):
		#self.callback = callback
		#self.x = 2
		#print(self.callback)
		def cb(value):
			PyThread_release_lock(interpreter_lock)
			print("cb", value)
			print(current_thread())
			print(callback)
		print(current_thread())
		if lib.rotenc_init(pin0, pin1, CBFUNC(cb)) != 0:
			raise IOError("Could not init GPIO")
