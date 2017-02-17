#!/bin/sh
cd ../bin/
#test case 1: test ls
echo "---------------------------------------------------"
echo "*********Test case 1: PROGRAM Output***************"
./rshell.exe <<'EOF'
ls
EOF
echo "*********Test case 1: EXPECTED Output**************"
ls
echo "---------------------------------------------------"