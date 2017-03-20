#include "../header/Base.h"
#include "../header/OutputRedirectAppend.h"

OutputRedirectAppend::OutputRedirectAppend() {
  this->left = NULL;
  this->right = NULL;
}

OutputRedirectAppend::~OutputRedirectAppend() {
  delete left;
  delete right;
}

OutputRedirectAppend::OutputRedirectAppend(Base* left, Base* right) {
  this->left = left;
  this->right = right;
}


bool OutputRedirectAppend::execute() {
  std::string temp = right->getExecutable();
    FILE *test = fopen(temp.c_str(), "a"); //w to empty file and recreate it, a to append
    int fd = fileno(test) , pid;
    
    bool success = false;
    
    pid=fork();
    
    if (pid==0) {
        dup2(fd,STDOUT_FILENO); //1 for output redirect, 0 for input redirect
        if(left->execute()){
            success = true;
        }
        fclose(test);
        exit(0);
    } 
    
  return success;
}