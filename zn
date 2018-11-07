#!/usr/bin/python3

def gcd(a, b):
    return a if b == 0 else gcd(b, a % b)

n = int(input())
g = []
for i in range(n):
    if gcd(n, i) == 1:
        g.append(i)
print(g)