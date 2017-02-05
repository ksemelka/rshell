#pragma once
#include "Connector.h"

class Or : public Connector {
public:
	Or();
	~Or();
	bool execute();
};
