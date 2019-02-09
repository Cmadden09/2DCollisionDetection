#pragma once
#include "manifold.h"
#include "boundingCircle.h"
#include "line.h"
#include "AABB.h"
#include "entity.h"
#include <iostream>

using namespace std;

class collisionDetection
{
public:
	collisionDetection()
	{
		
	}

	//float CircleToLine(line line, boundingCircle circle);
	bool CircleToLine(entity* circle, entity* line, manifold* Manifold);

	bool AABBtoAABB(entity* box1, entity* box2, manifold* Manifold);
	bool AABBtoCircle(entity* box, entity* circle, manifold* Manifold);
	bool CircleToCircle(entity* c1, entity* c2, manifold* Manifold);

	bool checkCollisions(entity* player, entity* collidable, manifold* manifold);

private:
	
};
