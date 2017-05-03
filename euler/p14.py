#! /usr/bin/env python
# -*- coding:utf-8 -*-

dp=range(1000000)

def dfs(n):
    if n==1: return 1
    res=0
    if n%2==1:
        temp=dfs(3*n+1)
        if 3*n<1000000:
            dp[3*n]=temp
    else:
        temp=dfs(n/2)
        if n/2<1000000:
            dp[n/2-1]=temp
    return temp+1

def main():
    for i in range(1000000):
        dp[i]=0
    res=1
    rmax=1
    dp[0]=1
    for i in range(1000000):
        if dp[i]==0:
            dp[i]=dfs(i+1)
            if rmax<dp[i]:
                res=i+1
                rmax=dp[i]
    print res

if __name__=='__main__':
    main()
