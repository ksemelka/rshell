#include "../header/Base.h"
#include "../header/Pipe.h"

Pipe::Pipe() {
  this->left = NULL;
  this->right = NULL;
}

Pipe::~Pipe() {
  delete left;
  delete right;
}

Pipe::Pipe(Base* left, Base* right) {
  this->left = left;
  this->right = right;
}


bool Pipe::execute() {
  if(((this->left)->execute())){
    return (this->right)->execute();
  }
  return false;
}