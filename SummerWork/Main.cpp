//#include <glew.h>
#include <GL/glut.h>
#include <iostream>
#include "boundingCircle.h"
#include "AABB.h"
#include "line.h"
#include <glm/glm.hpp>
#include "player.h"

#include "CollisionDetection.h"
using namespace std;



const float PI = 3.142; 

player *Player = new player();

glm::vec2 xBounds(0, 600);
glm::vec2 yBounds(0, 400);
	

void keyboard(unsigned char key, int x, int y)
{


	switch (key)
	{
	case 'w':
		Player->setVelocity(glm::vec2(0, 0.3));

		break;

	case 'a':
		Player->setVelocity(glm::vec2(-0.3, 0));
		
		break;

	case 'd':
		Player->setVelocity(glm::vec2(0.3, 0));
		
		break;

	case 's':
		Player->setVelocity(glm::vec2(0, -0.3));
		
		break;
	
	case '1':
		Player->deleteCurrentGame();
		Player->loadLineToCircle();

		break;
	case '2':
		Player->deleteCurrentGame();
		Player->loadAABBtoAABB();


		break;
	case '3':
		Player->deleteCurrentGame();
		Player->loadAABBtoCircle();


		break;
	case '4':
		Player->deleteCurrentGame();
		Player->loadCircleToCircle();


		break;
	}
}



void renderscene(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	Player->drawEntities();
	
	glutSwapBuffers();
}


void timer(int value)
{
	Player->setPositions();

	renderscene();

	Player->checkCollisions();

	glutTimerFunc(5, timer, 0);
}

int main(int argc, char **argv)
{
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(200, 200);
	glutInitWindowSize(600, 400);
	glutCreateWindow("Bounding Boxes");
	gluOrtho2D(0, 600, 0, 400);
	glClearColor(0.0, 0.0, 0.0, 1.0);

	bool running = true;

	Player->loadLineToCircle();											
	

	while (running == true)
	{
		glutDisplayFunc(renderscene);

		glutTimerFunc(10, timer, 0);
		glutKeyboardFunc(keyboard);

		glutMainLoop();

	}

	return 0;
}