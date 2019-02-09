#include "boundingCircle.h"

float boundingCircle::getRadius() 
{ 
	return radius; 

};


glm::vec2 boundingCircle::getPosition()
{
	return position;
}

void boundingCircle::setVelocity(glm::vec2 speedChange) 
{ 
	velocity += speedChange; 

}

void boundingCircle::bounceBack(manifold* m)
{ 
	velocity += -m->getcontactnormal(1) / glm::vec2(400,400);
}




void boundingCircle::setPosition() 
{ 
	position += velocity; 

}

void boundingCircle::invertMotionX()
{
	velocity.x = -velocity.x;
}

void boundingCircle::invertMotionY()
{
	velocity.y = -velocity.y;
}

void boundingCircle::checkXPosition(glm::vec2 bound)
{
	if (position.x + radius> bound.y)
	{
		position.x = bound.y - radius;
		invertMotionX();
	}
	else if (position.x - radius < bound.x)
	{
		position.x = bound.x + radius;
		invertMotionX();
	}
}

void boundingCircle::checkYPosition(glm::vec2 bound)
{
	if (position.y + radius > bound.y)
	{
		position.y = bound.y - radius;
		invertMotionY();
	}
	else if (position.y - radius < bound.x)
	{
		position.y = bound.x + radius;
		invertMotionY();
	}
}

void boundingCircle::draw()
{
	int i;
	int triangleAmount = 40; //# of triangles used to draw circle

	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_LINE_LOOP);

	glVertex2f(position.x, position.y); // center of circle
	for (i = 0; i <= triangleAmount; i++) {

		if (i == 30)
			glColor3f(0, 1, 0);
		else
			glColor3f(1, 0, 0);


		glVertex2f(
			position.x + (radius * cos(i *  twicePi / triangleAmount)),
			position.y + (radius * sin(i * twicePi / triangleAmount))
			);
	}

	glEnd();
	glFlush();
}