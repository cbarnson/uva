#! python

# Problem #    : 546A
# Created on   : 2019-01-15 19:53:54


def Main():
    k, n, w = map(int, input().split(' '))
    tot = 0
    for i in range(1, w+1):
        tot += k * i
    
    if n >= tot:
        print(0)
    else:
        print(tot - n)


if __name__ == '__main__':
    Main()
