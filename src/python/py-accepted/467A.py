#! python

# Problem #    : 467A
# Created on   : 2019-01-15 20:33:19


def Main():
    n, cnt = int(input()), 0
    for i in range(n):
        x, y = map(int, input().split(" "))
        if y - x > 1:
            cnt += 1
    print(cnt)


if __name__ == '__main__':
    Main()
