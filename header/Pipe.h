#pragma once
#include "Connector.h"

class Pipe : public Connector {
public:
	Pipe();
	Pipe(Base*, Base*);
	~Pipe();
	bool execute();
	std::string getExecutable(){return "";};
};
