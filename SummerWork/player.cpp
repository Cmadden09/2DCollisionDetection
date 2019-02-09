#include "player.h"


player::player()
{
	CollisionDetection = new collisionDetection();
	Manifold = new manifold();
}

void player::loadLineToCircle()
{
	
	playerObject = new boundingCircle(50, glm::vec2(300, 200), glm::vec2(0));
	collidableObject = new line(glm::vec2(5, 350), glm::vec2(200, 10));	

}

void player::loadAABBtoAABB()
{
	playerObject = new AABB(glm::vec2(400, 200), glm::vec2(440, 240));
	collidableObject = new AABB(glm::vec2(205, 250), glm::vec2(245, 290));

}

void player::loadAABBtoCircle()
{
	playerObject = new AABB(glm::vec2(20, 330), glm::vec2(60, 370));
	collidableObject = new boundingCircle(50, glm::vec2(300, 200), glm::vec2(0));

}

void player::loadCircleToCircle()
{
	playerObject = new boundingCircle(30, glm::vec2(100, 200), glm::vec2(0));
	collidableObject = new boundingCircle(50, glm::vec2(300, 200), glm::vec2(0));
}

void player::movePlayer(glm::vec2 move)
{

}

entity* player::getPlayerObject()
{

	return playerObject;
}

entity* player::getcollidableObject()
{
	return collidableObject;
}


void player::drawEntities()
{
	playerObject->draw();
	collidableObject->draw();
}

void player::setPositions()
{
	playerObject->setPosition();
	collidableObject->setPosition();
}

void player::setVelocity(glm::vec2 speedChange)
{
	playerObject->setVelocity(speedChange);
}

void player::checkCollisions()
{

	if (CollisionDetection->checkCollisions(playerObject, collidableObject, Manifold) == true)
		playerObject->bounceBack(Manifold);

}


void player::deleteCurrentGame()
{
	delete playerObject;
	delete collidableObject;

}