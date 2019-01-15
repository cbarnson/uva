#! python

# Problem #    : 96A
# Created on   : 2019-01-14 21:37:58


def Main():
    s = input()
    if ('1' * 7 in s or '0' * 7 in s):
        print('YES')
    else:
        print('NO')


if __name__ == '__main__':
    Main()
