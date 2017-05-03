#! python

l1 = ['one','two','three','four','five','six','seven','eight','nine']
l2 = ['ten','eleven','twelve','thirteen','fourteen','fifteen','sixteen','seventeen','eighteen','nineteen']
l3 = ['twenty','thirty','forty','fifty','sixty','seventy','eighty','ninety']
l4 = ['hundred', 'thousand', 'and']

ans = 0
for i in l1:
    ans = ans + len(i)
temp1 = ans
for i in l2:
    ans = ans + len(i)
for i in l3:
    ans = ans + len(i) * 10 + temp1
temp2 = ans
for i in l1:
    ans = ans + (len(i) + len(l4[0])) * 100 + len(l4[2]) * 99 + temp2
ans = ans + len(l1[0]) + len(l4[1])
print ans
