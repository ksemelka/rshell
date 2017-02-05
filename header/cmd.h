#pragma once
#include <string>
#include <vector>
#include "Base.h"

class Cmd : public Base {
public:
	Cmd();
	~Cmd();
	bool execute();
private:
	std::string executable;
	std::vector< std::string > argumentList;
};
