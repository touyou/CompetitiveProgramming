#! python

s = raw_input()
l = len(s)
ans = 25 * l
for i in range(l):
    temp = s[:i] + '*' + s[i+1:]
    temp2 = temp[:l-i-1] + '*' + temp[l-i:]
#    print temp2
    if temp2 == temp2[::-1]:
        ans -= 1
if l == 1:
    ans = 0
elif s == s[::-1]:
    ans = 25*l
print ans
