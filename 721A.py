# Problem #    : 721A
# Created on   : 2018-11-05 16:53:23

def Main():
  n = int(input())
  s = input()
  while s != '':
    i = s.find('W')
    print(i)
    s = s[i+1:]

if __name__ == '__main__':
  Main()