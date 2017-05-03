#!/usr/bin/env python
#-*- coding:utf-8 -*-

from math import pow

def main():
	a = range(1,333)
	b = range(2,500)
	c = range(3,998)
	res = 1
	for i in a:
		for j in b:
			for k in c:
				if i < j < k:
					if i < j < k and pow(i,2)+pow(j,2)==pow(k,2) and i+j+k==1000:
						res = i*j*k
						print i, " ", j, " ", k
						break
			if res != 1:
				break
		if res != 1:
			break
	print res

if __name__ == '__main__':
	main()
