#! python

# Problem #    : 266B
# Created on   : 2019-01-15 20:46:42


def Main():
    n, t = map(int, input().split(" "))
    s = input()
    for i in range(t):
        s2 = s.replace("BG", "GB")
        s = s2
    print(s)


if __name__ == '__main__':
    Main()
