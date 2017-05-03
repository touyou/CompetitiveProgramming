#!/usr/bin/env python
#-*- coding:utf-8 -*-

def solve(d):
	s=str(d)
	l=len(s)
	for i in range(0,l):
		if s[i]!=s[l-i-1]:
			return 0
	return 1

def main():
	d,log = 0,0
	for i in range(100,999):
		for j in range(100,999):
			d = i*j
			if solve(d):
				log = max(log, d)
	print log

if __name__ == '__main__':
	main()
