#!/bin/sh
cd ../bin/
#test case 1: test '|' on valid command
echo "---------------------------------------------------"
echo "--------Test case 1: | on valid command------------"
cat ../tests/pipe_test/1.dat | ./rshell.exe > ../tests/pipe_test/1o.dat
#test case 2: test multiple '|'
echo "---------------------------------------------------"
echo "--------Test case 2: | on multiple pipes-----------"
cat ../tests/pipe_test/2.dat | ./rshell.exe > ../tests/pipe_test/2o.dat
echo "---------------------------------------------------"