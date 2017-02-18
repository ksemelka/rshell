#include "../header/Base.h"
#include "../header/Or.h"

Or::Or() {
  this->left = NULL;
  this->right = NULL;
}

Or::~Or() {
  delete left;
  delete right;
}

Or::Or(Base* left, Base* right) {
  this->left = left;
  this->right = right;
}

bool Or::execute() {
  if(!((this->left)->execute())){
    return (this->right)->execute();
  }
  return true;
}