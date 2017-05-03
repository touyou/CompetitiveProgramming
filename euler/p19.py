#! python

ndays = [31,28,31,30,31,30,31,31,30,31,30,31]
ldays = [31,29,31,30,31,30,31,31,30,31,30,31]
day = 0 # 0--Monday --> 6--Sunday
ans = 0

def isleap(year):
    if year % 4 == 0 and (year % 100 != 0 or year % 400 == 0):
        return True
    return False

day = (day + 365) % 7

for i in range(1901, 2001):
    if isleap(i):
        for j in ldays:
            if day == 6:
                ans = ans + 1
            day = (day + j) % 7
    else:
        for j in ndays:
            if day == 6:
                ans = ans + 1
            day = (day + j) % 7
print ans

