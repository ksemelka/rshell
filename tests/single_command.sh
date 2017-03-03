#!/bin/sh
cd ../bin/
#test case 1: test simple command with no parameters
echo "---------------------------------------------------"
echo "---------Test case 1: NO PARAMETERS----------------"
cat ../tests/single_command_test/1.dat | ./rshell.exe > ../tests/single_command_test/1o.dat
#test case 2: test simple command with one parameters
echo "---------------------------------------------------"
echo "---------Test case 2: ONE PARAMETER----------------"
cat ../tests/single_command_test/2.dat | ./rshell.exe > ../tests/single_command_test/2o.dat
#test case 3: test simple command with multiple parameters
echo "---------------------------------------------------"
echo "---------Test case 3: >1 PARAMETER-----------------"
cat ../tests/single_command_test/3.dat | ./rshell.exe > ../tests/single_command_test/3o.dat
#test case 4: test simple command with invalid parameters
echo "---------------------------------------------------"
echo "---------Test case 4: INVALID PARAMETER------------"
cat ../tests/single_command_test/4.dat | ./rshell.exe > ../tests/single_command_test/4o.dat
echo "---------------------------------------------------"
#test case 5: test simple command with invalid and validparameters
echo "---------------------------------------------------"
echo "------Test case 5: INVALID & VALID PARAMETER-------"
cat ../tests/single_command_test/5.dat | ./rshell.exe > ../tests/single_command_test/5o.dat
echo "---------------------------------------------------"
#test case 6: test simple command with invalid command
echo "---------------------------------------------------"
echo "---------Test case 6: INVALID COMMAND--------------"
cat ../tests/single_command_test/6.dat | ./rshell.exe > ../tests/single_command_test/6o.dat