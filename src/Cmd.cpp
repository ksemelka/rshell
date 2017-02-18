#include "../header/Base.h"
#include "../header/Cmd.h"

//Cmd::Cmd(){
//  this->executable = "";
//}

Cmd::Cmd(const std::string& raw){
  char* str = new char [raw.length()]; 
  std::strcpy(str,raw.c_str());
  char* point;
  
  point = strtok(str, " ");
  
  this->executable = point;
  point = strtok(NULL, " ");
  
  while(point != NULL){
    std::string temp = point;
    argumentList.push_back(temp);
    point = strtok(NULL, " ");
  }
}

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
  
  for(unsigned i = 0; i < size; i++){
    args[i+1] = (char*)(argumentList.at(i)).c_str();
  }
  
  args[size+1] = NULL;
  
  pid_t pid = fork();
  
  if(pid == 0){	//Child node
    if(execvp(args[0],args) == -1){
      perror("failed execution");
      return false;
    }
  }
  if(pid > 0){ //parent
    if( waitpid(-1,0,0) == -1){
      perror("failed waitpid");
      return false;
    }
  }
  
  return true;
}
