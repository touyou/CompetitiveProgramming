#coding: utf-8
import math
n = int(raw_input())
r = 1
for i in range(1, n+1):
    r = r * i
    while r % 10 == 0: r = r / 10
    if r >= 100000000000000000000: r = r % 100000000000000000000
print r % 1000000000,"\n"
