# Problem No.  : 10696
# Created on   : 2018-05-24 20:40:23
import sys
import functools


def Main():
    while True:
        n = int(input())
        if (n == 0):
            break
        print("f91(%d) = %d" % (n, f91(n)))


def f91(n):
    if (n <= 101):
        return 91
    return n - 10


if __name__ == '__main__':
    Main()
