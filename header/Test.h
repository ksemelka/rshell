#pragma once
#include "Decorator.h"
#include "Cmd.h"
#include <vector>
#include <string>

class Test : public Decorator {
public:
	Test();
	Test(const std::vector<std::string >&);
	~Test();
	bool execute();
	std::string getExecutable(){return "";};
protected:
	std::vector< std::string > argument;
};
