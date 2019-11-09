#!/usr/bin/env python
# coding: utf-8

def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a%b)

a = 1
b0 = 1
b = 2
p = [b0, b0*b+a]
q = [1, b]
res = 0

for i in range(2, 1000):
    p.append(b*p[i-1] + a*p[i-2])
    q.append(b*q[i-1] + a*q[i-2])
    if len(str(p[i])) > len(str(q[i])):
        res += 1

print res
