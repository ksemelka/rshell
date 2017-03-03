#!/bin/sh
cd ../bin/
#test case 1: exit
echo "---------------------------------------------------"
echo "---------Test case 1: EXIT ALONE-------------------"
cat ../tests/exit_test/1.dat | ./rshell.exe > ../tests/exit_test/1o.dat
#test case 2: exit in beggining
echo "---------------------------------------------------"
echo "---------Test case 2: EXIT BEGIN ------------------"
cat ../tests/exit_test/2.dat | ./rshell.exe > ../tests/exit_test/2o.dat
#test case 3: exit in end
echo "---------------------------------------------------"
echo "---------Test case 3: EXIT MIDDLE -----------------"
cat ../tests/exit_test/3.dat | ./rshell.exe > ../tests/exit_test/3o.dat
#test case 4: exit in middle
echo "---------------------------------------------------"
echo "---------Test case 4: EXIT END------------------"
cat ../tests/exit_test/4.dat | ./rshell.exe > ../tests/exit_test/4o.dat