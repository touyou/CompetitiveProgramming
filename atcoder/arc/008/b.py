#! /usr/bin/env python
# coding: utf-8

(n, m) = map(int, raw_input().split(' '))
name = raw_input()
kit = raw_input()

ndict = {}
kdict = {}

for i in name:
    ndict.setdefault(i, 0)
    ndict[i] += 1
for i in kit:
    kdict.setdefault(i, 0)
    kdict[i] += 1

res = 0
for k, v in ndict.iteritems():
    if kdict.get(k) == None: res = -1; break
    res = max(res, (v + kdict[k] - 1) / kdict[k])

print res
