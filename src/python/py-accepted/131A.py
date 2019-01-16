#! python

# Problem #    : 131A
# Created on   : 2019-01-15 20:16:51


def Main():
    l = input()
    a, b = l[0], l[1:]

    if l.isupper() or (a.islower() and (not b or b.isupper())):
        print(l.swapcase())
    else:
        print(l)


if __name__ == '__main__':
    Main()
