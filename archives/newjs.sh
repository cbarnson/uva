#!/bin/sh

pn="// Problem #    : $1$2"
ts="// Created on   : "$(date +"%Y-%m-%d %H:%M:%S")

if [ -f "wdl.py" ] ; then
    wdl.py $@
fi

if [ -f "default_cf.js" ] ; then
    cp "default_cf.js" $1$2.js
    echo "$ts" | cat - $1$2.js > tmp.js && mv tmp.js $1$2.js
    echo "$pn" | cat - $1$2.js > tmp.js && mv tmp.js $1$2.js
fi

cat $1$2.js
echo ""
echo "all done"
code $1$2.js

# 1st optional argument: 
# if have TEMPLATE, and > 0 arguments, use 1st arg to create new file as copy of TEMPLATE and rename
# if [ -f ${TEMPLATE} ]; then
#   if [ "$#" -gt 0 ]; then
#     echo $1${PY_EXT}
#     timestamp | cat - ${TEMPLATE} > tmp && mv tmp $1${PY_EXT}
#     echo "# Problem #    : "$1 | cat - $1${PY_EXT} > tmp && mv tmp $1${PY_EXT}
#     echo '' | cat - $1${PY_EXT} > tmp && mv tmp $1${PY_EXT}
#     echo ${SHEBANG} | cat - $1${PY_EXT} > tmp && mv tmp $1${PY_EXT}
#     sed -i 's/\r//' $1${PY_EXT}
#   fi
# fi


# echo "Success!"
