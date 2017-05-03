#!/usr/bin/env python
#-*- coding:utf-8 -*-

def main():
	x,y = 0,0;
	for i in range(1,101):
		x += i*i
		print i
	for i in range(1,101):
		y += i
	y = y*y
	res = x-y
	if res < 0:
		res *= -1
	print res

if __name__ == '__main__':
	main()

