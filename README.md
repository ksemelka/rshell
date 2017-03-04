# RShell

## List of Known Bugs
#### Wrong error message with unexisting command (i.e. ls-a)
#### When prompted with a && connector and empty second command (i.e. ls &&), user is not asked for a second command
#### Segmentation fault when prompted with a || connector and empty second 
#### When passing something in quotation marks, it is pased on. i.e. echo "hello" prints "hello" instead of hello
#### test returns false when only '-e' '-d' or '-f' is passed
