#!/bin/bash

# input

if [ "$#" -lt 2 ]; then
    echo "Error, invalid number of arguments..."
    echo "Usage: new.sh cc|py|js 123 [A]"
    exit
else
    echo "good"
fi

if [ "$#" -ge 3 ]; then
    dl="$3"
fi

ext="$1"

if [ -n ${dl} ]; then
    base="$2$3"
else
    base="$2"
fi
filename="${base}.${ext}"


print() {
    echo "---------------------------------"
    echo "Settings"
    echo "---------------------------------"
    echo "Mode    : ${ext}"
    echo "Target  : ${base}"
    echo "Filename: ${filename}"
    echo "---------------------------------"
}
print


cc_new() {
    pn="// Problem #    : ${base}"
    ts="// Created on   : "$(date +"%Y-%m-%d %H:%M:%S")
    if [ -f "default_cf.cc" ]; then
        echo "good, found template"
        cp "default_cf.cc" "${filename}"
        ls
        echo "created copy of template"
        echo "now adding header"
        echo "$ts" | cat - ${filename} > tmp && mv tmp ${filename}
        echo "$pn" | cat - ${filename} > tmp && mv tmp ${filename}
        ls
        echo "--------------"
        cat ${filename}
        echo "--------END-----"
    fi
}

py_new() {
    sb="#! python"
    pn="# Problem #    : ${base}"
    ts="# Created on   : "$(date +"%Y-%m-%d %H:%M:%S")
    if [ -f "default_cf.py" ]; then
        echo "good, found template"
        cp "default_cf.py" "${filename}"
        ls
        echo "created copy of template"
        echo "now adding header"
        echo "$ts" | cat - ${filename} > tmp && mv tmp ${filename}
        echo "$pn" | cat - ${filename} > tmp && mv tmp ${filename}
        echo ""    | cat - ${filename} > tmp && mv tmp ${filename}
        echo "$sb" | cat - ${filename} > tmp && mv tmp ${filename}
        ls
        echo "--------------"
        cat ${filename}
        echo "--------END-----"
    fi
}

js_new() {
    pn="// Problem #    : ${base}"
    ts="// Created on   : "$(date +"%Y-%m-%d %H:%M:%S")
    if [ -f "default_cf.js" ]; then
        echo "good, found template"
        cp "default_cf.js" "${filename}"
        ls
        echo "created copy of template"
        echo "now adding header"
        echo "$ts" | cat - ${filename} > tmp && mv tmp ${filename}
        echo "$pn" | cat - ${filename} > tmp && mv tmp ${filename}
        ls
        echo "--------------"
        cat ${filename}
        echo "--------END-----"
    fi
}

echo "Deleting .in and .out files..."
find -maxdepth 1 -f "*.in" -delete
find -maxdepth 1 -f "*.out" -delete
echo "Deleting has completed."

if [ -n ${dl} ]; then
    if [ -f "wdl.py" ] ; then
        echo "Downloading sample data from Codeforces..."
        python wdl.py $2 $3
        echo "Downloading is complete."
    fi
fi

echo "Creating new source template..."

if [ "${ext}" == "cc" ] ; then
    echo "cc mode"
    cc_new
fi

if [ "${ext}" == "py" ] ; then
    echo "py mode"
    py_new
fi

if [ "${ext}" == "js" ] ; then
    echo "js mode"
    js_new
fi

echo "Creation is complete."

exit

# t=
# f=


# if [ -n "$1" ]; then
#     echo "$1 is set to $1"
# fi
# exit


# t="cc"
# if [ "$#" -eq 2 ] ; then
#     t=$1
#     f=$2
# else
#     echo "Usage: run.sh cc|py filename"
#     echo "----------------------------"
#     exit
# fi

# if [ $t == "cc" ] ; then
#     cc_mode=1
# fi

# if [ $t == "py" ] ; then
#     py_mode=1
# fi

# print() {
#     echo "Type  : ${t}"
#     echo "Target: ${f}"
# }
# # print

# # if [ -z ${cc_mode} ] ; then
# #     echo "cc_mode is unset";
# # else
# #     echo "cc_mode is set to '$cc_mode'";
# # fi

# if [ -n "${cc_mode}" ] ; then
#     echo "set"
# else
#     echo "not set"
# fi

# if [ -n "${py_mode}" ] ; then
#     echo "set"
# else
#     echo "not set"
# fi

# # if [ cc_mode == 1 ] ; then
# #     echo "C++ mode"
# # else if [ py_mode == 1 ] ; then
# #     echo "Python mode"
# # fi

