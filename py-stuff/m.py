#!/usr/bin/python

from pathlib import Path
import os.path

# can do ""macros""
p = print
r = range
for i in r(10):
    p(i)


fname = 'new'
if (os.path.isfile(fname)):
    print('yes, %s is a file' % (fname))
else:
    print('no, %s is not a file' % (fname))

f = Path("new")
if f.is_file():
    print ('is file')

if f.is_dir():
    print ('is dir')
else:
    print ('is not dir')

if f.exists():
    print ('exists')

a = b = c = 'hello'
print(a)
print(b)

