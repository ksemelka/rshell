#pragma once
#include "Connector.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

class OutputRedirectAppend : public Connector {
public:
	OutputRedirectAppend();
	OutputRedirectAppend(Base*, Base*);
	~OutputRedirectAppend();
	bool execute();
	std::string getExecutable(){return "";};
};
