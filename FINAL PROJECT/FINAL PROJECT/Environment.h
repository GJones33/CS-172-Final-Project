#ifndef ENVIRONMENT_H_
#define ENVIRONMENT_H_

#include "Entity.h"

class Environment : public Entity {
public:
	Environment(int); //pass the int for the assosciated floor layout
	string whatAmI() { return "Environment"; }
};

#endif