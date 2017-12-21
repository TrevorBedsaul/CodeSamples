#!/bin/bash
clang++ counter.cpp
echo 'enter the exponent for counter.cpp:'
read exp #reading in exponent
t=0
n=5
i=0
if [[ "$exp" == 'quit' ]] ; then
    exit 1
fi
while [[ $i -lt $n ]]; do  #loop through 5 times
    echo 'Running iteration '$((i + 1))'...'
    tmp=`./a.out ${exp} | tail -1` #gets time from each run
    t=$((t + tmp))
    echo 'time taken: '${tmp}' ms'
    i=$((i + 1))
done
echo ${n}' iterations took '${t}' ms'  #printing results
echo 'Average time was '$((t / n))' ms'
