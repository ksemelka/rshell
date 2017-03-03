#!/bin/sh
cd ../bin/
#test case 1: test simple command with no parameters
echo "---------------------------------------------------"
echo "---------Test case 1: HASH MIDDLE----------------"
cat ../tests/commented_command_test/1.dat | ./rshell.exe > ../tests/commented_command_test/1o.dat