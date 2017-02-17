#include "../header/Base.h"
#include "../header/And.h"

And::And() {
  this->left = NULL;
  this->right = NULL;
}

And::~And() {
  delete left;
  delete right;
}

And::And(Base* left, Base* right) {
  this->left = left;
  this->right = right;
}


bool And::execute() {
  if(((this->left)->execute())){
    return (this->right)->execute();
  }
  return false;
}