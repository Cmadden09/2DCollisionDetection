#pragma once
#include <glm/glm.hpp>
#include <GL/glut.h>
#include "manifold.h"
#include "entity.h"


class AABB : public entity
{
public:

	AABB(){}
	AABB(glm::vec2 min, glm::vec2 max) :  min(min), max(max)
	{
		width = max.x - min.x;
		height = max.y - min.y;
		position = glm::vec2(min.x, min.y);
		velocity = glm::vec2(0, 0);
	}

	void draw();
	void setVelocity(glm::vec2 speedChange);
	void setPosition();
	void bounceBack(manifold* m);

	entity* returnType()
	{
		return this;
	}

	glm::vec2 getMin()
	{
		return min;
	}
	
	glm::vec2 getMax()
	{
		return max;
	}


	glm::vec2 min;
	glm::vec2 max;
private:
	
	float width;
	float height;

	glm::vec2 velocity;
	glm::vec2 position;

};