#! python

# Problem #    : 50A
# Created on   : 2019-01-14 21:29:26


def Main():
    m, n = map(int, input().split(' '))
    val = m * n
    cnt = int(val / 2)
    print(cnt)


if __name__ == '__main__':
    Main()
