#pragma once
#include "Decorator.h"

class Test : public Decorator {
public:
	Test();
	Test(Base*);
	~Test();
	bool execute();
};
