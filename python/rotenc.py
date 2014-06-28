import os
import inspect
from ctypes import *

class RotEnc(object):
	def __init__(self, pinEnc0, pinEnc1, pinBtn, callback):
		libPath = os.path.abspath(os.path.dirname(inspect.getfile(inspect.currentframe())) + "/../libht1632c-py.so")
		self.lib = cdll.LoadLibrary(libPath)
		
		CBFUNC = CFUNCTYPE(None, c_int)
		self.lib.rotenc_init.argtypes = [c_int, c_int, c_int, CBFUNC]
		self.lib.rotenc_init.restype = c_int
		self.lib.rotenc_wait.argtypes = []
		self.lib.rotenc_wait.restype = c_int
		
		print("Initializing rotary encoder")
		if callback is not None:
			cb = CBFUNC(callback)
		else:
			cb = cast(None, CBFUNC)
		if self.lib.rotenc_init(pinEnc0, pinEnc1, pinBtn, cb) != 0:
			raise IOError("Could not init GPIO")
	
	def wait(self):
		return self.lib.rotenc_wait()
