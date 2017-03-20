#pragma once
#include "Connector.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

class OutputRedirect : public Connector {
public:
	OutputRedirect();
	OutputRedirect(Base*, Base*);
	~OutputRedirect();
	bool execute();
	std::string getExecutable(){return "";};
};
