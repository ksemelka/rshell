#include "../header/Base.h"
#include "../header/Semicolon.h"

Semicolon::Semicolon() {
  this->left = NULL;
  this->right = NULL;
}

Semicolon::~Semicolon() {
  delete left;
  delete right;
}

Semicolon::Semicolon(Base* left, Base* right) {
  this->left = left;
  this->right = right;
}

bool Semicolon::execute() {
  (this->left)->execute();
  return (this->right)->execute();
}