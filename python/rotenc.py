from ctypes import *
lib = cdll.LoadLibrary('../libht1632c.so')

from threading import *

CBFUNC = CFUNCTYPE(None, c_int)
lib.rotenc_init.argtypes = [c_int, c_int, c_int, CBFUNC]
lib.rotenc_init.restype = c_int

class RotEnc(object):
	def __init__(self, pinEnc0, pinEnc1, pinBtn, callback):
		print("Initializing rotary ecoder")
		if lib.rotenc_init(pinEnc0, pinEnc1, pinBtn, CBFUNC(callback)) != 0:
			raise IOError("Could not init GPIO")
