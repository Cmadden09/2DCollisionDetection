#pragma once
//#include <glm/detail/type_vec2.hpp>
//#include <glm/detail/type_vec3.hpp>
#include <glm/glm.hpp>
#include <GL/glut.h>
#include "entity.h"
#include "manifold.h"


class boundingCircle : public entity
{
public:
	boundingCircle(){}

	boundingCircle(float radius, glm::vec2 pos, glm::vec2 vel) : radius(radius), position(pos), velocity(vel) 
	{
		velocity = glm::vec2(0, 0);
	};

	float getRadius();



	void setVelocity(glm::vec2 speedChange);

	void bounceBack(manifold* m);

	//void bounceBack(line line) {velocity = velocity * line.getNormal(); }

	void setPosition(); 
	glm::vec2 getPosition();

	void invertMotionX();
	

	void invertMotionY();

	void checkXPosition(glm::vec2 bound);

	void checkYPosition(glm::vec2 bound);
	

	void draw();


	entity* returnType()
	{
		return this;
	}


private:
	const float PI = 3.142;
	float radius;
	glm::vec2 position;
	glm::vec2 velocity;
};
