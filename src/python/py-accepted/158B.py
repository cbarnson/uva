#! python

# Problem #    : 158B
# Created on   : 2019-01-14 22:25:35


def Main():
    n = int(input())
    t = 0
    arr = [int(x) for x in input().split(' ')]
    arr.sort()

    i = 0
    j = len(arr) - 1
    k = 0
    m = 4

    while j >= i:
        if i is j:
            k += 1
            break

        while arr[i] + arr[j] <= m and j > i:
            arr[j] += arr[i]
            i += 1

        k += 1
        j -= 1

    print(k)


if __name__ == '__main__':
    Main()
