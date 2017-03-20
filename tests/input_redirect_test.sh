#!/bin/sh
cd ../bin/
#test case 1: test '>' existant file
echo "---------------------------------------------------"
echo "----------------Test case 1: <---------------------"
cat ../tests/input_redirect_test/1.dat | ./rshell.exe > ../tests/input_redirect_test/1o.dat
#test case 2: test '>' on non-existent file
echo "---------------------------------------------------"
echo "---------Test case 2: << on existent----------------"
cat ../tests/input_redirect_test/2.dat | ./rshell.exe > ../tests/input_redirect_test/2o.dat
echo "---------------------------------------------------"