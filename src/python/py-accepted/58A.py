#! python

# Problem #    : 58A
# Created on   : 2019-01-14 23:43:53


def Main():
    s = input()
    hello = 'hello'
    j = 0
    for i in range(len(hello)):
        j = s.find(hello[i], j)
        if j is -1:
            print('NO')
            return
        j += 1

    print('YES')


if __name__ == '__main__':
    Main()
