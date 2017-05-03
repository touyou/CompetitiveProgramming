#! /usr/bin/env python
# coding: utf-8

# φ (n) を調べる -> wikiでこんな公式みつける φ (n) = n * Π (1 - 1/Pk)
# 変形して φ (n) / n = Π (1 - 1/Pk) の最小 -> 1 - 1/Pk < 1なのでkが大きいほど
# 小さいことがわかる
# P1P2...Pk<=1000000を探しませう

# Pythonの機能使うと素数列挙簡単らしいけど…

x = []
for i in range(1000005): x.append(True)
x[0] = x[1] = False
prime = []
for i in range(2, 1000005):
    if x[i]:
        prime.append(i)
        for j in range(i*2, 1000005, i): x[j] = False

ret = 1; c = 0
while True:
    if ret * prime[c] > 1000000: break
    ret *= prime[c]; c += 1

print ret
