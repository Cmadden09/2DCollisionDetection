#include "AABB.h"

void AABB::draw()
{
	glColor3f(1, 1, 1);

	glBegin(GL_LINE_LOOP);

	glVertex2f(min.x, min.y + height);
	glVertex2f(min.x, min.y);

	glVertex2f(min.x + width, min.y);
	glVertex2f(min.x + width, min.y + height);

	glEnd();
	glFlush();
}


void AABB::setVelocity(glm::vec2 speedChange) 
{ velocity += speedChange; }


void AABB::setPosition() 
{ 
	min += velocity;
	max += velocity;

}

void AABB::bounceBack(manifold* m)
{ 
	velocity *= glm::vec2(-1, -1); 
	//velocity += m->getcontactnormal(1) * glm::vec2(0.03, 0.03);
}