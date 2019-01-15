#! python

# Problem #    : 236A
# Created on   : 2019-01-14 23:41:28


def Main():
    cnt = len(set(input()))
    print('IGNORE HIM!' if cnt & 1 else 'CHAT WITH HER!')


if __name__ == '__main__':
    Main()
