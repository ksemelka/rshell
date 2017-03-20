#pragma once
#include "Connector.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

class Pipe : public Connector {
public:
	Pipe();
	Pipe(Base*, Base*);
	~Pipe();
	bool execute();
	std::string getExecutable(){return "";};
};
