#pragma once
#include "Base.h"

class Connector : public Base {
public:
	Connector() : left(NULL), right(NULL) { }
	Connector(Base*, Base*);
	~Connector();
	virtual bool execute() = 0;
private:
	Base *left, *right;
};