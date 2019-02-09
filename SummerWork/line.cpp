#include "line.h"


void line::setVelocity(glm::vec2 speedChange)
{
	velocity += speedChange;
}

void line::setPosition()
{
	P1.x += velocity.x;
	P2.x += velocity.x;

	P1.y += velocity.y;
	P2.y += velocity.y;

}

void line::bounceBack(manifold* m)
{
	velocity *= glm::vec2(-1, -1);
}



glm::vec2 line::getNormal() { return norm; }


glm::vec2 line::getP1() { return P1; }


glm::vec2 line::getP2() { return P2; }



void line::draw()
{
	glColor3f(1, 1, 1);

	glBegin(GL_LINES);

	glVertex2f(P1.x, P1.y);
	glVertex2f(P2.x, P2.y);


	glEnd();
	glFlush();
}
