#!/usr/bin/env python
# coding: utf-8

n = int(raw_input())

res = n * 15
for i in range(1, int(n / 10) + 2):
    temp = (n - i * 10) * 15
    if temp < 0: temp = 0
    temp += i * 100
    res = min(res, temp)
print res
