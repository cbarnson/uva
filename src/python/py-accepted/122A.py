#! python

# Problem #    : 122A
# Created on   : 2019-01-15 19:45:38


def Main():
    lucky = [ 4, 7, 44, 47, 74, 77, 444, 447, 474, 744, 477, 747, 774, 777 ]
    n = int(input())
    for luck in lucky:
        if n % luck == 0:
            print('YES')
            return
    print('NO')
    



if __name__ == '__main__':
    Main()
