#pragma once
#include "Base.h"

class Connector : public Base {
public:
	Connector();
	~Connector();
	virtual bool execute() = 0;
private:
	Base *left, *right;
};
