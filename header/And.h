#pragma once
#include "Connector.h"

class And : public Connector {
public:
	And();
	~And();
	bool execute();
};
