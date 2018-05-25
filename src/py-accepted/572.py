# Problem No.  : 572
# Created on   : 2018-05-24 22:10:02
import sys
import functools

m = 0
n = 0

di = [-1, -1, -1, 0, 0, 1, 1, 1]
dj = [-1, 0, 1, -1, 1, -1, 0, 1]

g = []


def ff(i, j):
    global g
    if (i < 0 or j < 0 or i >= m or j >= n):
        return 0
    if (g[i][j] != '@'):
        return 0

    ans = 1
    g[i] = g[i][:j] + '*' + g[i][j+1:]
    for k in range(0, 8):
        ans += ff(i + di[k], j + dj[k])
    return ans


def Main():
    global g, m, n
    while True:
        m, n = map(int, input().split())
        if (m == 0):
            break
        g = []
        for i in range(0, m):
            line = input().strip()
            g.append(line)

        cnt = 0
        for i in range(0, m):
            for j in range(0, n):
                if (g[i][j] == '@'):
                    ff(i, j)
                    cnt = cnt + 1

        print(cnt)


if __name__ == '__main__':
    Main()
