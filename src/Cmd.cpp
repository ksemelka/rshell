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
  
  args[0] = (char*)executable.c_str();
  
  for(unsigned i = 1; i < size+1; i++){
    args[i] = (char*)(argumentList.at(i)).c_str();
  }
  
  args[size+1] = NULL;
  
  pid_t pid = fork();
  
  if(pid == 0){	//Child node
    if(execvp(args[0],args) == -1){
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
