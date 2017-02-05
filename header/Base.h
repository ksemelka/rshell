#pragma once

class Base {
public:
	Base() { } ;
	~Base() { } ;
	virtual bool execute() = 0;
};
