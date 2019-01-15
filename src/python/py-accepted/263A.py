#! python

# Problem #    : 263A
# Created on   : 2019-01-14 22:13:53


def Main():
    arr = [input().split(' ') for l in range(0, 5)]
    for i in range(len(arr)):
        for j in range(len(arr[i])):
            if arr[i][j] == str(1):
                print(abs(2-i) + abs(2-j))


if __name__ == '__main__':
    Main()
