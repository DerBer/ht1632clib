# -*- coding: utf-8 -*-
import os
import inspect
from ctypes import *

class HT1632C(object):
	def __init__(self, rotation):
		libPath = os.path.abspath(os.path.dirname(inspect.getfile(inspect.currentframe())) + "/../libht1632c-py.so")
		self.lib = cdll.LoadLibrary(libPath)
		
		self.lib.ht1632c_init.argtypes = [c_int]
		self.lib.ht1632c_init.restype = c_int
		self.lib.ht1632c_pwm.argtypes = [c_byte]
		self.lib.ht1632c_pwm.restype = None
		self.lib.ht1632c_clip.argtypes = [c_int, c_int, c_int, c_int]
		self.lib.ht1632c_clip.restype = None
		self.lib.ht1632c_plot.argtypes = [c_int, c_int, c_byte]
		self.lib.ht1632c_plot.restype = None
		self.lib.ht1632c_line.argtypes = [c_int, c_int, c_int, c_int, c_byte]
		self.lib.ht1632c_line.restype = None
		self.lib.ht1632c_box.argtypes = [c_int, c_int, c_int, c_int, c_byte]
		self.lib.ht1632c_box.restype = None
		self.lib.ht1632c_putchar.argtypes = [c_int, c_int, c_char, c_void_p, c_byte, c_byte]
		self.lib.ht1632c_putchar.restype = c_int
		self.lib.ht1632c_putstr.argtypes = [c_int, c_int, c_char_p, c_void_p, c_byte, c_byte]
		self.lib.ht1632c_putstr.restype = c_int
		self.lib.ht1632c_fontwidth.argtypes = [c_void_p]
		self.lib.ht1632c_fontwidth.restype = c_int
		self.lib.ht1632c_fontheight.argtypes = [c_void_p]
		self.lib.ht1632c_fontheight.restype = c_int
		
		print("Loading GPIO SPI module")
		os.system("gpio load spi")
		print("Initializing HT1632C")
		if self.lib.ht1632c_init(rotation) != 0:
			raise IOError("Could not init display")
		self.font4x5num = self.lib.font_4x5_num
		self.font7x8num = self.lib.font_7x8_num
		self.font4x6 = self.lib.font_4x6
		self.font6x8 = self.lib.font_6x8
		self.font7x12 = self.lib.font_7x12
		self.font8x12 = self.lib.font_8x12
		self.font12x16 = self.lib.font_12x16
	
	def pwm(self, value):
		self.lib.ht1632c_pwm(value)
	
	def sendframe(self):
		self.lib.ht1632c_sendframe()
	
	def clear(self):
		self.lib.ht1632c_clear()
	
	def clip(self, x0, y0, x1, y1):
		self.lib.ht1632c_clip(x0, y0, x1, y1)
	
	def plot(self, x, y, color):
		self.lib.ht1632c_plot(x, y, color)
	
	def line(self, x0, y0, x1, y1, color):
		self.lib.ht1632c_line(x0, y0, x1, y1, color)
	
	def box(self, x0, y0, x1, y1, color):
		self.lib.ht1632c_box(x0, y0, x1, y1, color)
	
	def putchar(self, x, y, c, font, color, bg):
		return self.lib.ht1632c_putchar(x, y, c, font, color, bg)
	
	def putstr(self, x, y, s, font, color, bg):
		return self.lib.ht1632c_putstr(x, y, c_char_p(s.encode("ascii")), font, color, bg)
	
	def fontwidth(self, font):
		return self.lib.ht1632c_fontwidth(font)
	
	def fontheight(self, font):
		return self.lib.ht1632c_fontheight(font)
