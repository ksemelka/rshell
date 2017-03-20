#pragma once
#include <stdlib.h>
#include <string>
#include <vector>
#include <cstring>
#include "Base.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

class Cmd : public Base {
public:
	Cmd();
	Cmd(const std::string&);
	Cmd(const std::string& , const std::vector<std::string>&);
	~Cmd();
	bool execute();
	std::string getExecutable();
private:
	std::string executable;
	std::vector< std::string > argumentList;
};
