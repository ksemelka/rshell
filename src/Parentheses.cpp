#include "../header/Base.h"
#include "../header/Parentheses.h"

Parentheses::Parentheses() {
  this->node = NULL;
}

Parentheses::~Parentheses() {
  delete node;
}

Parentheses::Parentheses(Base* node) {
  this->node = node;
}


bool Parentheses::execute() {
  return (this->node)->execute();
}