#! python

# Problem #    : 231A
# Created on   : 2019-01-14 21:19:31


def Main():
    n = int(input())
    cnt = 0
    for i in range(0, n):
        if sum(list(map(int, input().split(' ')))) > 1: 
            cnt += 1
    else:
        print(cnt)


if __name__ == '__main__':
    Main()
