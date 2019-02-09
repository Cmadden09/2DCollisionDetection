#pragma once
#include "entity.h"
#include <GL/glut.h>
#include <glm/detail/type_vec2.hpp>
#include <glm/detail/type_vec3.hpp>
#include "manifold.h"
//using namespace glm;

class line : public entity
{
public:
	line(){}
	line::line(glm::vec2 P1, glm::vec2 P2) : P1(P1), P2(P2)
	{
		norm = -glm::vec2(P2.y - P1.y), glm::vec2(P2.x - P1.x);
		velocity = glm::vec2(0, 0);
	}

	void setVelocity(glm::vec2 speedChange);
	void setPosition();
	void bounceBack(manifold* m);


	entity* returnType()
	{
		return this;
	}


	glm::vec2 getNormal();
	glm::vec2 getP1();
	glm::vec2 getP2();

	void draw();

private:
	
	glm::vec2 P1;
	glm::vec2 P2;
	glm::vec2 norm;

	glm::vec2 velocity;
	glm::vec2 position;
};
