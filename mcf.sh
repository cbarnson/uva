#!/bin/sh

# variables
FILES=(in out)
DIRECTORY=src/codeforces/accepted
CPP_EXT=.cc
TEMPLATE=src/templates/template${CPP_EXT}

# Usage preamble:
echo "Usage:" $0 " <completed prob file in $(pwd) to move to ${DIRECTORY}>"
echo "No args: refresh I/O files"
echo "1 arg  : see above, and moves file indicated by filename in arg 1 to ${DIRECTORY}"
echo "e.g."
echo "$0 123"
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

# use 1st arg as file name (e.g. 123 for 123.cc) to move to accepted
# DIRECTORY=src/accepted
if [ "$#" -eq 1 ]; then
  if [ -f $1${CPP_EXT} ]; then
    echo moving $1${CPP_EXT} to accepted

    # be more careful moving this
    if [ -d "$DIRECTORY" ]; then
      echo "directory exists"
      
      cp $1${CPP_EXT} "$DIRECTORY"/$1${CPP_EXT}
      if [ -f "$DIRECTORY"/$1${CPP_EXT} ]; then
        rm $1${CPP_EXT}
      else
        echo warning, $1${CPP_EXT} did not copy to "$DIRECTORY" correctly.. skipping removal step
      fi
    fi

    # if there was an .exe left behind, remove it
    if [ -f $1".exe" ]; then
      echo removing unneeded exe $1".exe"
      rm $1".exe"
    fi

    if [ -f $1${CPP_EXT}~ ]; then
	rm $1${CPP_EXT}~
    fi

    find -type f -regex './in[0-9]*~?' -delete

  fi
fi

echo "Success!"
