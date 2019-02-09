#pragma once
#include <glm/glm.hpp>
#include "CollisionDetection.h"
#include "manifold.h"
#include "Entity.h"
#include "boundingCircle.h"
#include "line.h"
#include "AABB.h"

class player
{
public:
	player();

	void loadLineToCircle();
	void loadAABBtoAABB();
	void loadAABBtoCircle();
	void loadCircleToCircle();

	void movePlayer(glm::vec2 move);

	entity* getPlayerObject();
	entity* getcollidableObject();

	void drawEntities();
	void setPositions();
	void setVelocity(glm::vec2 speedChange);

	void checkCollisions();

	void deleteCurrentGame();



private:
	entity* playerObject;
	entity* collidableObject;

	collisionDetection *CollisionDetection;
	manifold* Manifold;
};