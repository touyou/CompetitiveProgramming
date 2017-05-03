#!/usr/bin/env python
#-*- coding:utf-8 -*-

def main():
	#prime = [2,3,5,7,11,13,15,17,19]
	num = [1,1,1,1,1,1,1,1,1,1,11,1,13,1,1,2,17,1,19,1]
	res=2*2*2*3*3*5*7
	for i in num:
		res *= i
	print res

if __name__ == '__main__':
	main()


