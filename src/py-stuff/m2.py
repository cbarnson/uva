#!/usr/bin/python

x = 3
y = x**2

print(x,y)

# from
def do(i, j):
    print('do %d %d' % (i, j))


n, m = 2, 10
b = []
for i in range(n):
    for j in range(m):
        do(i, j)
        b.append((i, j))

print('or...')

# Remember: (/, %), 2nd operand is 2nd dimension
a = []
for k in range(n*m):
    do(k / m, k % m)
    a.append((int(k / m), k % m))

print('a : ', a, '-----', 'b : ', b)
assert(a == b)
