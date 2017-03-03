#pragma once
#include "Base.h"

class Decorator : public Base {
public:
	Decorator();
	Decorator(Base*);
	~Decorator();
	virtual bool evaluate() = 0;
protected:
    Base *node;
};