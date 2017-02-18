#pragma once
#include <cstdlib> //NULL

class Base {
public:
	Base() { } ;
	virtual ~Base() { } ;
	virtual bool execute() = 0;
};
