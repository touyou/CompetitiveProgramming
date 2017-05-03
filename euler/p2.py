#! /usr/bin/env python

def fib():
    a, b = 1,2
    ans = []
    while True:
        a, b = b, a+b
        if a % 2 == 0:
            ans.append(a)
        if b > 4000000:
            break
    return ans

def main():
    ans = fib()
    sums = 0
    print ans
    while True:
        sums += ans.pop()
        if ans == []:
            break
    print sums

if __name__ == '__main__':
    main()
