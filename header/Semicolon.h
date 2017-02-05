#pragma once
#include "Connector.h"

class Semicolon : public Connector {
public:
	Semicolon();
	~Semicolon();
	bool execute();
};
