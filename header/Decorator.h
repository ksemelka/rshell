#pragma once
#include "Base.h"

class Decorator : public Base {
public:
	Decorator();
	Decorator(Base*);
	~Decorator();
	virtual bool execute() = 0;
};