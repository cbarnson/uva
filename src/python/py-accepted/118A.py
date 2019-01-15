#! python

# Problem #    : 118A
# Created on   : 2019-01-14 20:55:34

def Main():
    vowels = "AOYEUIaoyeui"
    s = input().lower()
    for let in set(s):
        if let in vowels: 
            s = s.replace(let, '')
        elif let.isalpha():
            s = s.replace(let, '.' + let)
    print(s)
    
if __name__ == '__main__':
    Main()
