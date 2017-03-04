#!/bin/sh
cd ../bin/
#test case 1: test simple command with no parameters
echo "---------------------------------------------------"
echo "---------Test case 1: Running ()----------------"
cat ../tests/test_test/1.dat | ./rshell.exe > ../tests/test_test/1o.dat
#test case 2: test simple command with one parameters
echo "---------------------------------------------------"
echo "---------Test case 2: Running () w/ '&& || ;'----------------"
cat ../tests/test_test/2.dat | ./rshell.exe > ../tests/test_test/2o.dat
#test case 3: test simple command with multiple parameters
