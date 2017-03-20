#include "../header/Base.h"
#include "../header/Pipe.h"

Pipe::Pipe() {
  this->left = NULL;
  this->right = NULL;
}

Pipe::~Pipe() {
  delete left;
  delete right;
}

Pipe::Pipe(Base* left, Base* right) {
  this->left = left;
  this->right = right;
}


bool Pipe::execute() {
  // pid_t pid;
  int ret;
  int pipefd[2];
  int savestdin = dup(0);
  int savestdout = dup(1);
  
  
  ret = pipe(pipefd);
  
  if (ret == -1) {
    perror("pipe");
    return false;
  }
  
  // pid = fork();
  bool success = false;
  // if (pid == 0) {
    //CHILD
    close(1);
    dup2(pipefd[1], STDOUT_FILENO);
    left->execute();
    close(pipefd[1]);
    dup2(savestdout, STDOUT_FILENO);
  // }
  // else {
    close(0);
    dup2(pipefd[0],STDIN_FILENO); //1 for output redirect, 0 for input redirect
    close(pipefd[0]);
    
    if(right->execute()){
        success = true;
    }
    
    dup2(savestdin, STDIN_FILENO);
  // }
  
  close(savestdin);
  close(savestdout);
  
  return success;
}