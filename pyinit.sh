#!/bin/sh

# variables
FILES=(in out)
DIRECTORY=src/py-accepted
PY_EXT=.py
TEMPLATE=template${PY_EXT}

# Usage preamble:
echo "Usage:" $0 "<next problem> <completed prob file in $(pwd) to move to ${DIRECTORY}>"
echo "No args: refresh I/O files"
echo "1 arg  : refresh I/O, make copy of template and set filename to argument 1"
echo "2 arg  : see above, and moves file indicated by filename in arg 2 to ${DIRECTORY}"
echo "e.g."
echo "$0 123 456"
echo ""

timestamp() {
  echo "# Created on   : "$(date +"%Y-%m-%d %H:%M:%S")
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
    echo $1${PY_EXT}
    timestamp | cat - ${TEMPLATE} > tmp && mv tmp $1${PY_EXT}
    echo "# Problem No.  : "$1 | cat - $1${PY_EXT} > tmp && mv tmp $1${PY_EXT}
  fi
fi

# 2nd optional argument:
# use 2nd arg as file name (e.g. 123 for 123.cc) to move to accepted
# DIRECTORY=src/accepted
if [ "$#" -eq 2 ]; then
  if [ -f $2${PY_EXT} ]; then
    echo moving $2${PY_EXT} to accepted

    # be more careful moving this
    if [ -d "$DIRECTORY" ]; then
      echo "directory exists"
      
      cp $2${PY_EXT} "$DIRECTORY"/$2${PY_EXT}
      if [ -f "$DIRECTORY"/$2${PY_EXT} ]; then
        rm $2${PY_EXT}
      else
        echo warning, $2${PY_EXT} did not copy to "$DIRECTORY" correctly.. skipping removal step
      fi
    fi

    # if there was an .exe left behind, remove it
    if [ -f $2".exe" ]; then
      echo removing unneeded exe $2".exe"
      rm $2".exe"
    fi
  fi
fi

echo "Success!"