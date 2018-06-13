# Problem No.  : 445
# Created on   : 2018-05-26 16:31:19
import sys
import functools
from collections import deque


def Main():
    while True:
        n = int(input())
        if (n == 0):
            break


def Test():
    for line in sys.stdin:
        i = 0
        while i < len(line):
            c = line[i]
            if c is '!' or c is '\n':
                sys.stdout.write('\n')
                i += 1
                continue

            x = 0
            while c.isdigit():
                x += int(c)
                i += 1
                c = line[i]

            for j in range(0, x):
                if c is 'b':
                    sys.stdout.write(' ')
                else:
                    sys.stdout.write(c)

            i += 1


if __name__ == '__main__':
    # Main()
    Test()
