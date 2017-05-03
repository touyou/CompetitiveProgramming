#!/usr/bin/env python
#-*- coding:utf-8 -*-

import math

MAX = 2000000
#MAX = 20
def main():
	s = 2
	n = True
	for i in range(3, MAX, 2):
		j = 3
		while j <= math.sqrt(i):
			if i%j == 0:
				n = False
				break
			j += 2
		if n:
			#print i
			s += i
		n = True
	print s

if __name__ == '__main__':
	main()
