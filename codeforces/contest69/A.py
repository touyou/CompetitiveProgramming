#! /usr/bin/env python

def solve(n):
    len = 2^n
    sum = 0
    for i in range(1, len-1):
        sum += i
    be = solve(n-1)
    ol = solve(n-2)
    sum = sum - (2^(n-1))^2 + be - ((2^(n-2))^2 - ol)*2
    return sum

def main():
    n = int(raw_input())
    ans = solve(n)
    print ans

if __name__ == '__main__':
    main()
