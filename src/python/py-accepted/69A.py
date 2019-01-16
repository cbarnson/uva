#! python

# Problem #    : 69A
# Created on   : 2019-01-15 20:08:32


def Main():
    n, a = int(input()), [0, 0, 0]
    for i in range(0, n):
        dt = [int(x) for x in input().split(" ")]
        for j in range(3):
            a[j] += dt[j]
    
    if any(a):
        print("NO")
    else:
        print("YES")


if __name__ == '__main__':
    Main()
