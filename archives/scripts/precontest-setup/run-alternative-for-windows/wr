#!/bin/sh


# This is the 'run' script, but for windows (home pc), for some reason, using the -Og flag messes up and the output 'sol' exe
# doesn't execute properly (fails with error code), so use this for windows (home pc)

# same usage as in option 2, but matches the LAST UPDATED *.cc file and uses that (best way!!)
myfile=`ls -t1 *.cc | head -n 1`
echo $myfile
g++ $myfile -g -std=c++11 -Wall -Wextra -Wconversion -Wshadow -o sol || exit

# expects input files of the form 1.in, something.in, 2.in, etc.
# expects output files to diff against of the form 1.out, or, 1.ans, etc. (first char after '.' is o or a, followed by 2 more characters)
for i in *.in; do
    echo --- $i
    ./sol < $i > o && (diff -y o ${i::-3}.[ao]?? > t || cat t) || cat o
done
