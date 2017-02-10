#pragma once
#include <cstdlib> //NULL

class Base {
public:
	Base() { } ;
	~Base() { } ;
	virtual bool execute() = 0;
};
