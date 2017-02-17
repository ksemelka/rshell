#include "../header/Base.h"
#include "../header/Cmd.h"

//Cmd::Cmd(){
//  this->executable = "";
//}

Cmd::Cmd(const std::string& exec,const std::vector<std::string>& aList){
  this->executable = exec;
  for(unsigned i = 0; i < aList.size(); i++){
    argumentList.push_back(aList.at(i));
  }
}

Cmd::~Cmd() {
}

bool Cmd::execute() {
  unsigned size = (argumentList.size() + 1);
  char* args[100]; //
  char* file = (char*)executable.c_str();
  
  for(unsigned i = 0; i < size; i++){
    args[i] = (char*)(argumentList.at(i)).c_str();
  }
  
  if(size == 0){
    args[0] = NULL;
  }else{
    args[size] = NULL;
  }
  
  pid_t pid = fork();
  
  if(pid == 0){	//Child node
    if(execvp(file,args) == -1){
      return false;
    }
  }
  if(pid > 0){ //parent
    if( waitpid(-1,0,0) == -1){
      return false;
    }
  }
  
  return true;
}
