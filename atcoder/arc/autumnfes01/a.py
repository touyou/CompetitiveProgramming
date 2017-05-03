(n, t) = map(int, raw_input().split(' '))
p = raw_input().split(' ')
s = []
for i in range(n):
    si = raw_input().split(' ')
    s.append(si)
t = []
for i in range(n):
    ti = raw_input().split(' ')
    t.append(ti)

# 単純シュミレーション
np = []; nt = 0
for i in range(n):
    np.append(0)
ret = 0
while nt <= t:

