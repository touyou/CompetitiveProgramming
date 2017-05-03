#!/usr/bin/env python
# coding: utf-8

(n, m) = map(int, (raw_input().split(' ')))
cases = range(1, n+1)

d = 0
for i in range(m):
    nd = int(raw_input())
    cnt = 0
    for j in cases:
        if j == nd:
            cases[cnt] = d
            d = nd
        cnt += 1

for i in cases:
    print i
