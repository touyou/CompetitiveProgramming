#!/usr/bin/env python
#-*- coding:utf-8 -*-

isp=range(0,1000000)
p=[]

def init():
    for i in range(2, 1000000):
        if isp[i]==i:
            p.append(i)
            for j in range(i*2,1000000,i):
                isp[j]=0

def count(n):
    res=1
    for i in p:
        cnt=0
        if i>n: break
        while n%i==0:
            n/=i
            cnt+=1
        res*=(cnt+1)
    return res

def main():
    init()
    n=0
    res=0
    for i in range(1,1000000):
        n+=i
        if count(n)>=500:
            res=n
            break
    print res

if __name__ == '__main__':
    main()


