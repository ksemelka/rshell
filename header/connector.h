#pragma once
#include "Base.h"

class Connector : public Base {
public:
	connector();
	~connector();
	virtual bool execute() = 0;
private:
	Base *left, *right;
};
