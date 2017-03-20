#pragma once
#include "Connector.h"

class And : public Connector {
public:
	And();
	And(Base*, Base*);
	~And();
	bool execute();
	std::string getExecutable(){return "";};
};
