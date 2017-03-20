#pragma once
#include "Connector.h"
#include "Cmd.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>


class Cmd;

class InputRedirect : public Connector {
public:
	InputRedirect();
	InputRedirect(Base*, Base*);
	~InputRedirect();
	bool execute();
	std::string getExecutable(){return "";};
};
