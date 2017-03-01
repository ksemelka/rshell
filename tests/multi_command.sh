#!/bin/sh
cd ../bin/
#test case 1: test simple command with no parameters
echo "---------------------------------------------------"
echo "---------Test case 1: AND----------------"
cat ../tests/multi_command_test/1.dat | ./rshell.exe > ../tests/multi_command_test/1o.dat
#test case 2: test simple command with one parameters
echo "---------------------------------------------------"
echo "---------Test case 2: OR----------------"
cat ../tests/multi_command_test/2.dat | ./rshell.exe > ../tests/multi_command_test/2o.dat
#test case 3: test simple command with multiple parameters
echo "---------------------------------------------------"
echo "---------Test case 3: SEMI-----------------"
cat ../tests/multi_command_test/3.dat | ./rshell.exe > ../tests/multi_command_test/3o.dat
#test case 4: test simple command with invalid parameters
echo "---------------------------------------------------"
echo "---------Test case 4: COMBINED------------"
cat ../tests/multi_command_test/4.dat | ./rshell.exe > ../tests/multi_command_test/4o.dat
echo "---------------------------------------------------"
exit
