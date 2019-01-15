#! python

# Problem #    : 116A
# Created on   : 2019-01-14 23:33:10


def Main():
    n = int(input())
    mi = 0
    curr = 0
    for i in range(n):
        exit, enter = map(int, input().split(' '))
        # print(enter, exit)
        curr -= exit
        curr += enter
        mi = max(mi, curr)
    print(mi)


if __name__ == '__main__':
    Main()
