#include "../header/Base.h"
#include "../header/Test.h"
#include <iostream>

Test::Test() {
  this->node = NULL;
}

Test::~Test() {
  delete node;
}

Test::Test(Base* node) {
  this->node = node;
}


bool Test::execute() {
  if(((this->node)->execute())){
      std::cout << "(True)" << std::endl;
    return true;
  }
  std::cout << "(False)" << std::endl;
  return false;
}