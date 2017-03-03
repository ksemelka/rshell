#include "../header/Base.h"
#include "../header/Decorator.h"

Decorator::Decorator() {
	this->node = NULL;
}

Decorator::Decorator(Base* node) {
	this->node = node;
}

Decorator::~Decorator() {
	delete node;
}
