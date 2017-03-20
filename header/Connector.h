#pragma once
#include "Base.h"

class Connector : public Base {
public:
	Connector();
	Connector(Base*, Base*);
	~Connector();
	virtual bool execute() = 0;
	virtual std::string getExecutable() = 0;
protected:
	Base *left, *right;
};