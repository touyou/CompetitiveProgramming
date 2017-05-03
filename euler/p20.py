#! /usr/bin/env python
# -*- coding:utf-8 -*-
def main():
    n=1L
    for i in range(2,101):
        n*=i
    s=str(n)
    res=0
    for i in range(len(s)):
        res+=int(s[i])
    print res

if __name__=='__main__':
    main()
