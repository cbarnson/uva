# Problem #    : 4A
# Created on   : 2019-01-11 22:42:54

def Main():
    x = int(input())
    if x > 2:
        x -= 2
        print('NO' if x & 1 else 'YES')
    else:
        print('NO')

if __name__ == '__main__':
    Main()
