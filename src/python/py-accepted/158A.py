#! python

# Problem #    : 158A
# Created on   : 2019-01-14 20:45:14

def Main():
    n, k = map(int, input().split(' '))
    arr = list(map(int, input().split(' ')))
    cnt = 0
    for i in arr:
        if i >= arr[k - 1] and i > 0:
            cnt += 1
    
    print(cnt)
        

if __name__ == '__main__':
    Main()
