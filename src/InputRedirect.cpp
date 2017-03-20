#include "../header/Base.h"
#include "../header/InputRedirect.h"

InputRedirect::InputRedirect() {
  this->left = NULL;
  this->right = NULL;
}

InputRedirect::~InputRedirect() {
  delete left;
  delete right;
}

InputRedirect::InputRedirect(Base* left, Base* right) {
  this->left = left;
  this->right = right;
}


bool InputRedirect::execute() {
    std::string temp = right->getExecutable();
    
    int fd = open(temp.c_str(), O_RDONLY, 0);
    int stdin_copy = dup(0);
    
    bool success = false;
    
        close(0);
        dup2(fd,STDIN_FILENO); //1 for output redirect, 0 for input redirect
        close(fd);
        
        if(left->execute()){
            success = true;
        }
        
        close(fd);
        dup2(stdin_copy, STDIN_FILENO);
        
        close(stdin_copy);
    
  return success;
  
}