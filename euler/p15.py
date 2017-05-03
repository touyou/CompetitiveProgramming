#! /usr/bin/env python
# -*- coding:utf-8 -*-
def main():
    res=1L
    for i in range(21,41):
        res*=i
    for i in range(1,21):
        res/=i
    print res

if __name__=='__main__':
    main()
