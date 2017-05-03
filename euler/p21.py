#! python

dnum = []

def d(n):
    s = 0
    for i in range(1,n):
        if n % i == 0:
            s += i
    return s

def main():
    for i in range(1,10001):
        dnum.append(d(i))
    print dnum[5]
    res = 0
    for i in range(0, 10000):
        dr = d(dnum[i])
        if dr == i+1 and dnum[i] != i+1: res += i+1
    print res

if __name__=='__main__':
    main()
