#!/usr/bin/env python
# coding:utf-8

import sys

x = str(sys.stdin.readline().strip())
s = str(sys.stdin.readline().strip())

res = []
for word in s:
    if word != x:
        res.append(word)

ans = ''.join(res)

print ans
