#!/bin/bash

file=`ls -t1 *.js | head -n 1`
echo $file

if [ -d "js-accepted" ] ; then
    mv $file "js-accepted"
fi

# equivalently,
find -maxdepth 1 -name "[0-9].in" -delete
find -maxdepth 1 -name "[0-9].out" -delete


echo "all done"
exit