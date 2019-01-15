#!python

# Problem #    : 1A
# Created on   : 2019-01-12 07:40:39

def Main():
    arr = [int(x) for x in input().split(' ')]
    n, m, a = arr[0], arr[1], arr[2]
    x = int(n / a) + bool(n % a)
    y = int(m / a) + bool(m % a)
    print(x * y)

if __name__ == '__main__':
    Main()
