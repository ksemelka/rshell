#include "../header/Base.h"
#include "../header/Cmd.h"
#include "../header/Test.h"
#include <cstdio>

Cmd::Cmd(const std::string& raw){
  std::string temp = raw;
  
  while (temp.at(0) == ' ') {   // Remove leading and trailing whitespace
    temp = temp.substr(1, temp.size() - 1);
  }
  while (temp.at(temp.size() - 1) == ' ') {
    temp = temp.substr(0, temp.size() - 2);
  }
  if (temp.at(0) == '[') {
    this->executable = "test";
    temp = temp.substr(1, temp.size() - 2);
  }
  
  char* str = new char [temp.length()]; 
  std::strcpy(str,temp.c_str());
  char* point;
  
  point = strtok(str, " ");
  
  if (this->executable != "test") {
    this->executable = point;
    point = strtok(NULL, " ");
  }
  
  while(point != NULL){
    std::string temp2 = point;
    argumentList.push_back(temp2);
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
  if(this->executable == "exit"){
    exit (0);
  }
  
  if(executable == "test"){
    Base* test_command = new Test(argumentList);
    return test_command->execute();
  }
  
  unsigned size = (argumentList.size());
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
