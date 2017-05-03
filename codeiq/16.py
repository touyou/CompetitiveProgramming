#! python

m = int(raw_input())
num = []
for i in range(0, m):
    flag = True
    num.append(raw_input().split('.'))
    if len(num[i]) > 4:
        flag = False
    for j in num[i]:
        if not j:
            flag = False
        elif int(j) < 0 or int(j) > 255:
            flag = False
    if flag:
        print 'True'
    else:
        print 'False'

