#!/usr/bin/env python
# coding: utf-8

c = str(raw_input())
n = len(c)
bit = 0
cnt = 0

for i in c:
    if c == 'o':
        bit |= 1<<cnt
    cnt += 1

