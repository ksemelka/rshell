#pragma once
#include "Connector.h"

class Or : public Connector {
public:
	Or();
	Or(Base*, Base*);
	~Or();
	bool execute();
	std::string getExecutable(){return "";};
};
