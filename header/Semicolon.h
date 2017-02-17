#pragma once
#include "Connector.h"

class Semicolon : public Connector {
public:
	Semicolon();
	Semicolon(Base*, Base*);
	~Semicolon();
	bool execute();
};
