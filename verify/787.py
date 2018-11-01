# Problem #    : 787
# Created on   : 2018-11-01 00:54:22

def Main():
  while True:
    x = []
    x = list(map(int, input().split()))
    # try:
    # except:
    #   return
    del x[-1]
    mx = x[0]
    for i in range(len(x)):
      s = x[i]
      for j in range(i, len(x)):
        if i == j:
          s = x[j]
        else:
          s *= x[j]
      mx = max(mx, s)
    print(mx)

if __name__ == '__main__':
  Main()