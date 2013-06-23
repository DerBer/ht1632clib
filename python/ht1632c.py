from ctypes import *
lib = cdll.LoadLibrary('../libht1632c.so')

lib.ht1632c_putchar.argtypes = [c_int, c_int, c_char, c_void_p, c_byte]

class HT1632C(object):
	def __init__(self):
		lib.ht1632c_init()
		self.font6x8 = lib.font_6x8
	
	def pwm(self, value):
		lib.ht1632c_pwm(value)
	
	def sendframe(self):
		lib.ht1632c_sendframe()
	
	def clear(self):
		lib.ht1632c_clear()
	
	def plot(self, x, y, color):
		lib.ht1632c_plot(x, y, color)
	
	def line(self, x0, y0, x1, y1, color):
		lib.ht1632c_line(x0, y0, x1, y1, color)
	
	def putchar(self, x, y, c, font, color):
		lib.ht1632c_putchar(x, y, c, font, color)
