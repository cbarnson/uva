#! python

# Problem #    : 266A
# Created on   : 2019-01-14 22:10:03


def Main():
    n, s = int(input()), input()

    init = s
    arr = ['RR', 'GG', 'BB']
    for x in arr:
        while s.find(x) != -1:
            s = s.replace(x, x[0])
    print(len(init) - len(s))


if __name__ == '__main__':
    Main()
