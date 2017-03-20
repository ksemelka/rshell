#pragma once
#include <cstdlib> //NULL
#include <string>

class Base {
public:
	Base() { } ;
	virtual ~Base() { } ;
	virtual bool execute() = 0;
	virtual std::string getExecutable() = 0;
};
