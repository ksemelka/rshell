#!/bin/sh
cd ../bin/
#test case 1: test simple command with no parameters
echo "---------------------------------------------------"
echo "---------Test case 1: NO PARAMETERS----------------"
echo "*********Test case 1: PROGRAM Output***************"
./rshell.exe <<'EOF'
ls
EOF
kill $!
echo "*********Test case 1: EXPECTED Output**************"
ls
echo "---------------------------------------------------"
#test case 2: test simple command with one parameters
echo "---------------------------------------------------"
echo "---------Test case 2: ONE PARAMETER----------------"
echo "*********Test case 2: PROGRAM Output***************"
./rshell.exe <<'EOF'
ls -a
EOF
kill $!
echo "*********Test case 2: EXPECTED Output**************"
ls -a
echo "---------------------------------------------------"
#test case 3: test simple command with multiple parameters
echo "---------------------------------------------------"
echo "---------Test case 3: >1 PARAMETER-----------------"
echo "*********Test case 3: PROGRAM Output***************"
./rshell.exe <<'EOF'
git config user.name
EOF
kill $!
echo "*********Test case 3: EXPECTED Output**************"
git config user.name
echo "---------------------------------------------------"
#test case 4: test simple command with invalid parameters
echo "---------------------------------------------------"
echo "---------Test case 4: INVALID PARAMETER------------"
echo "*********Test case 4: PROGRAM Output***************"
./rshell.exe <<'EOF'
git config user.name
EOF
kill $!
echo "*********Test case 4: EXPECTED Output**************"
ls
echo "---------------------------------------------------"
#test case 5: test simple command with invalid and validparameters
echo "---------------------------------------------------"
echo "------Test case 5: INVALID & VALID PARAMETER-------"
echo "*********Test case 5: PROGRAM Output***************"
./rshell.exe <<'EOF'
git config user.nmae
EOF
kill $!
echo "*********Test case 5: EXPECTED Output**************"
git config user.nmae
echo "---------------------------------------------------"
#test case 5: test simple command with invalid command
echo "---------------------------------------------------"
echo "---------Test case 6: INVALID COMMAND--------------"
echo "*********Test case 6: PROGRAM Output***************"
./rshell.exe <<'EOF'
lr
EOF
kill $!
echo "*********Test case 6: EXPECTED Output**************"
lr
echo "---------------------------------------------------"