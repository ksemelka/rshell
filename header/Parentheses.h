#pragma once
#include "Decorator.h"

class Parentheses : public Decorator {
public:
	Parentheses();
	Parentheses(Base*);
	~Parentheses();
	bool execute();
};
