#!/usr/bin/env python
#-*- coding:utf-8 -*-

def main():
	f = range(2,200000)
	i = 0
	while True:
		for j in f:
			if j == f[i]:
				continue
			elif j%f[i]==0:
				f.remove(j)
		i += 1
		if i >= len(f):
			break
	res = f[10000]
	print res, " ", f[2]

if __name__ == '__main__':
	main()


