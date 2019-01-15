#! python

# Problem #    : 112A
# Created on   : 2019-01-14 21:45:38


def Main():
    a, b = input().lower(), input().lower()
    print(-1 if a < b else 1 if b < a else 0)

if __name__ == '__main__':
    Main()
