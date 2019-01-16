#! python

# Problem #    : 110A
# Created on   : 2019-01-15 20:50:10


def Main():
    s = input()
    t = sum([s.count(str(x)) for x in [4, 7]])
    if t is 4 or t is 7:
        print("YES")
        return
    print("NO")


if __name__ == '__main__':
    Main()
