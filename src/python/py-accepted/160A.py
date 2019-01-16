#! python

# Problem #    : 160A
# Created on   : 2019-01-15 20:00:55


def Main():
    n = int(input())
    arr = [int(x) for x in input().split(" ")]
    tot = sum(arr)
    cnt = 0
    tot2 = 0
    for el in reversed(sorted(arr)):
        tot2 += el
        tot -= el
        cnt += 1
        if tot2 > tot:
            break
    print(cnt)

if __name__ == '__main__':
    Main()
