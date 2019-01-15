#!/bin/bash

pn="// Problem #    : $1$2"
ts="// Created on   : "$(date +"%Y-%m-%d %H:%M:%S")

if [ -f "wdl.py" ] ; then 
    wdl.py $@
fi

file=$1$2.js
touch $file

echo -e "${pn}\n${ts}\n$(cat $file)" > $file

echo "Created file $file, with :"
cat $file
echo ""
echo "all done!"

