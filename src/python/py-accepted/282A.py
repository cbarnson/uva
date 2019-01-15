#! python

# Problem #    : 282A
# Created on   : 2019-01-14 21:33:20


def Main():
    n = int(input())
    x = 0
    for i in range(0, n):
        s = input()
        x = x + 1 if '++' in s else x - 1
    print(x)


if __name__ == '__main__':
    Main()
