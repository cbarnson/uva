#!/bin/sh

SHEBANG=#!/usr/bin/python3
PY_EXT=.py
TEMPLATE=$HOME/uva/src/templates/template${PY_EXT}

timestamp() {
  echo "# Created on   : "$(date +"%Y-%m-%d %H:%M:%S")
}

# 1st optional argument: 
# if have TEMPLATE, and > 0 arguments, use 1st arg to create new file as copy of TEMPLATE and rename
if [ -f ${TEMPLATE} ]; then
  if [ "$#" -gt 0 ]; then
    echo $1${PY_EXT}
    timestamp | cat - ${TEMPLATE} > tmp && mv tmp $1${PY_EXT}
    echo "# Problem #    : "$1 | cat - $1${PY_EXT} > tmp && mv tmp $1${PY_EXT}
    echo '' | cat - $1${PY_EXT} > tmp && mv tmp $1${PY_EXT}
    echo ${SHEBANG} | cat - $1${PY_EXT} > tmp && mv tmp $1${PY_EXT}
    sed -i 's/\r//' $1${PY_EXT}
  fi
fi


echo "Success!"
