#! /usr/bin/env python
# -*- coding:utf-8 -*-
def main():
    binary=2L**1000
    s=str(binary)
    res=0L
    for i in range(len(s)):
        res+=int(s[i])
    print res,len(s)

if __name__=='__main__':
    main()
