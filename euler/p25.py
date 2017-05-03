#! python

fib1 = 1
fib2 = 1
fib = 0
n = 2
while fib <= pow(10, 999):
    fib = fib1 + fib2
    fib1 = fib2
    fib2 = fib
    n += 1
print n
