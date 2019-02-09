#pragma once
#include <glm/glm.hpp>
//#include "manifold.h"

class manifold;

class entity 
{
public:
	virtual void draw() = 0;
	virtual void setVelocity(glm::vec2 speedChange) = 0;
	virtual void setPosition() = 0;
	virtual void bounceBack(manifold* m) = 0;

	virtual entity* returnType() = 0;

};