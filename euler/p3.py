#!/usr/bin/env python

#def p(prime, c):
#	if prime[c] != 0:
#		for i in range(0,len(prime)):
#			if i == c:
#				continue
#			elif prime[i]%prime[c] == 0:
#				prime[i] = 0
#	if c+1 == len(prime):
#		return prime
#	p(prime, c+1)
#	return prime

def main():
	d = 600851475143
	prime = range(2,10000)
#	s = p(prime, 0)
	i,m=0,0
	while i<len(prime):
		print "loop",i,"=",prime[i]
		if prime[i] == 0:
			i+=1
		elif d%prime[i]==0:
			d /= prime[i]
			print d, " ", prime[i]
			m=max(m,prime[i])
		else:
			i+=1
	print d, " ", m

if __name__ == '__main__':
	main()
