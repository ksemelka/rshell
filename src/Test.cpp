#include "../header/Base.h"
#include "../header/Test.h"
#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

Test::Test() {
  //this->node = NULL;
}

Test::~Test() {
//   /delete node;
}

Test::Test(const std::vector<std::string >& argument) {
  this->argument = argument;
}

bool Test::execute() {
  struct stat info;
    
    if(argument.size() > 2){
        std::cout << "(False)" << std::endl;
        return false;
    }else if(argument.size() == 1){
        if(stat( ((argument.at(0)).c_str()), &info ) != false){
            std::cout << "(True)" << std::endl;
            return true;
        }
    }else if(argument.size() == 2){
        if(stat( ((argument.at(1)).c_str()), &info ) != false){
            if(argument.at(0) == "-f"){
                
            }else if(argument.at(0) == "-d"){
                if(S_ISDIR(info.st_mode)){
                    std::cout << "(True)" << std::endl;
                    return true;
                }
                
                std::cout << "(False)" << std::endl;
                return false;
            }else if(argument.at(0) == "-f"){
                if(S_ISREG(info.st_mode)){
                    std::cout << "(True)" << std::endl;
                    return true;
                }
                
                std::cout << "(False)" << std::endl;
                return false;
            }
            std::cout << "(True)" << std::endl;
            return true;
        }
    }
    
  std::cout << "(False)" << std::endl;
  return false;
}