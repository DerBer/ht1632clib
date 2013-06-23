from ctypes import *
lib = cdll.LoadLibrary('../libht1632c.so')

lib.ht1632c_pwm.argtypes = [c_byte]
lib.ht1632c_plot.argtypes = [c_int, c_int, c_byte]
lib.ht1632c_line.argtypes = [c_int, c_int, c_int, c_int, c_byte]
lib.ht1632c_box.argtypes = [c_int, c_int, c_int, c_int, c_byte]
lib.ht1632c_putchar.argtypes = [c_int, c_int, c_char, c_void_p, c_byte]
lib.ht1632c_putstr.argtypes = [c_int, c_int, c_char_p, c_void_p, c_byte]

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
	
	def box(self, x0, y0, x1, y1, color):
		lib.ht1632c_box(x0, y0, x1, y1, color)
	
	def putchar(self, x, y, c, font, color):
		lib.ht1632c_putchar(x, y, c, font, color)
	
	def putstr(self, x, y, s, font, color):
		lib.ht1632c_putstr(x, y, s, font, color)
