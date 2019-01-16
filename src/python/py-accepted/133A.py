#! python

# Problem #    : 133A
# Created on   : 2019-01-15 20:14:13


def Main():
    l = input()
    s = "HQ9"
    for ch in s:
        if (l.find(ch) != -1):
            print("YES")
            return
    print("NO")


if __name__ == '__main__':
    Main()
