#!/bin/sh -x

f=`ls -t1 *.cc | head -n 1`
g=${f::-3}

echo "$f --> $g"

