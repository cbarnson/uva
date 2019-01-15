#! python

# Problem #    : 71A
# Created on   : 2019-01-14 20:52:39

def Main():
    n = int(input())
    for i in range(0, n):
        s = input()
        if len(s) > 10:
            s2 = s[0] + str(len(s) - 2) + s[-1]
            print(s2)
        else:
            print(s)

if __name__ == '__main__':
    Main()
