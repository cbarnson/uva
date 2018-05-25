# Problem No.  : 10812
# Created on   : 2018-05-24 23:39:37
import sys
import functools


def Main():
    while True:
        n = int(input())
        while (n > 0):
            n = n - 1
            s, d = map(int, input().split())
            x = s - d
            if (x < 0 or x & 1):
                print("impossible")
                continue
            print(d + int(x / 2), int(x / 2))
        break


if __name__ == '__main__':
    Main()
