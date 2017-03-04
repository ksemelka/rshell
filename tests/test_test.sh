#!/bin/sh
cd ../bin/
#test case 1: test simple command with no parameters
echo "---------------------------------------------------"
echo "---------Test case 1: Running w/ 'test'----------------"
cat ../tests/test_test/1.dat | ./rshell > ../tests/test_test/1o.dat
#test case 2: test simple command with one parameters
echo "---------------------------------------------------"
echo "---------Test case 2: Running w/ '[]'----------------"
cat ../tests/test_test/2.dat | ./rshell > ../tests/test_test/2o.dat
#test case 3: test simple command with multiple parameters
echo "---------------------------------------------------"
echo "---------Test case 3: Running 'test' w/ &&,||,; -----------------"
cat ../tests/test_test/3.dat | ./rshell > ../tests/test_test/3o.dat
#test case 4: test simple command with invalid parameters
echo "---------------------------------------------------"
echo "---------Test case : Running '[]' w/ &&,||,; ------------"
cat ../tests/test_test/4.dat | ./rshell > ../tests/test_test/4o.dat
echo "---------------------------------------------------"