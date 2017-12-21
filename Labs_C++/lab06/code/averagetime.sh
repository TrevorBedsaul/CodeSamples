#!/bin/bash
make #compiles the files
echo 'Enter files in this form: <dictionary_file.txt> <grid_file.txt>' #requests input
read dict grid #reads in files into seperate variables
t1=`./a.out ${dict} ${grid} | tail -1` #calls a.out and only takes the last lines
t2=`./a.out ${dict} ${grid} | tail -1`
t3=`./a.out ${dict} ${grid} | tail -1`
t4=`./a.out ${dict} ${grid} | tail -1`
t5=`./a.out ${dict} ${grid} | tail -1`
echo 'Average time = '$((t1+t2+t3+t4+t5))'/5 milliseconds' #sums and prints it with a division sign and 5 after
