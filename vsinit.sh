#!/bin/sh

# variables
FILES=(in out)
DIRECTORY=src/accepted
CPP_EXT=.cc
TEMPLATE=src/templates/template${CPP_EXT}
VISUAL_STUDIO_TARGET=../source/repos/UvaCpp/UvaCpp.Core/main.cpp

# Usage preamble:
echo "Usage:" $0 "<next problem>"
echo "1 arg  : refresh I/O, make copy of template and set filename to argument 1"
echo "e.g."
echo "$0 123 456"
echo ""

timestamp() {
  echo "// Created on   : "$(date +"%Y-%m-%d %H:%M:%S")
}

# create blank I/O files
for f in ${FILES[@]}
do
  if [ -f ${f} ]; then
    rm ${f}
    touch ${f}
  fi
done

# 1st optional argument: 
# if have TEMPLATE, and > 0 arguments, use 1st arg to create new file as copy of TEMPLATE and rename
if [ -f ${TEMPLATE} ]; then
  if [ "$#" -gt 0 ]; then
    echo $1${CPP_EXT}
    timestamp | cat - ${TEMPLATE} > tmp && mv tmp $1${CPP_EXT}
    echo "// Problem #    : "$1 | cat - $1${CPP_EXT} > tmp && mv tmp ${VISUAL_STUDIO_TARGET}
  fi
fi

# Do same, but create persistent copy for this uva repo
if [ -f ${TEMPLATE} ]; then
  if [ "$#" -gt 0 ]; then
    echo $1${CPP_EXT}
    timestamp | cat - ${TEMPLATE} > tmp && mv tmp $1${CPP_EXT}
    echo "// Problem #    : "$1 | cat - $1${CPP_EXT} > tmp && mv tmp $1${CPP_EXT}
  fi
fi

echo "Success!"
