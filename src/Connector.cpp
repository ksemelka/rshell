#include "../header/Base.h"
#include "../header/Connector.h"

Connector::Connector() {
	this->left = NULL;
	this->right = NULL;
}

Connector::Connector(Base* left, Base* right) {
	this->left = left;
	this->right = right;
}



Connector::~Connector() {
	delete left;
	delete right;
}
