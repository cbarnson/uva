#! python

# Problem #    : 339A
# Created on   : 2019-01-14 21:51:12


def Main():
    l = [int(x) for x in input().split('+')]
    l.sort()
    s = ''
    for i in l:
        s = s + '+' + str(i)
    s = s.lstrip('+')
    print(s)


if __name__ == '__main__':
    Main()
