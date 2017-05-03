#! /usr/bin/env python
# coding: utf-8

import math

n = int(raw_input())
x = []; y = []; t = []; r = []
for i in range(n):
    (xi,yi,ti,ri) = map(int, raw_input().split(' '))
    x.append(xi); y.append(yi); t.append(ti); r.append(ri)

rap = []
for i in range(n):
    trap = []
    for j in range(n):
        if i == j: trap.append(-1); continue
        ret = hypot(x[i]-x[j], y[i]-y[j]) / min(t[i], r[j])
        trap.append(ret)
    rap.append(trap)

# 1秒間のラグの考慮
# time[i] = iまでの最短 → iから配る時？
