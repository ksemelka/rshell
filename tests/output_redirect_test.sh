#!/bin/sh
cd ../bin/
#test case 1: test '<' on non existent file
echo "---------------------------------------------------"
echo "--------Test case 1: < on non existent-------------"
cat ../tests/output_redirect_test/1.dat | ./rshell.exe > ../tests/output_redirect_test/1o.dat
#test case 2: test '<<' on existent file
echo "---------------------------------------------------"
echo "---------Test case 2: << on existent----------------"
cat ../tests/output_redirect_test/2.dat | ./rshell.exe > ../tests/output_redirect_test/2o.dat
#test case 3: test '<<' on non existent file
echo "---------------------------------------------------"
echo "---------Test case 3: << on non existent-----------------"
cat ../tests/output_redirect_test/3.dat | ./rshell > ../tests/output_redirect_test/3o.dat
#test case 4: test '<' on existent file
echo "---------------------------------------------------"
echo "---------Test case 4: < on existent----------------"
cat ../tests/output_redirect_test/4.dat | ./rshell > ../tests/output_redirect_test/4o.dat
echo "---------------------------------------------------"