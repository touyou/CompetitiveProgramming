#! python

m = [0] * 1000
res = 0
l = 0

def calc(d):
    m[0] = 1 % d
    for i in range(1, d):
        m[i] = m[i - 1] * 10 % d
        for j in range(0, i):
            if m[i] == m[j]:
                return i - j

for d in range(1, 1000):
    temp = calc(d)
    if temp > l:
        res = d
        l = temp

print res
