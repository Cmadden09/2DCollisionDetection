#include "CollisionDetection.h"
#include "utilities.h"
#include <glm/glm.hpp>
#include <iostream>
using namespace std;

bool collisionDetection::CircleToLine(entity* Circle, entity* Line, manifold* Manifold)
{
	boundingCircle* circle = dynamic_cast<boundingCircle*>(Circle->returnType());
	line* line1  = dynamic_cast<line*>(Line->returnType());


	glm::vec2 p1 = line1->getP1();
	glm::vec2 p2 = line1->getP2();
	glm::vec2 center = circle->getPosition();
	float radius = circle->getRadius();



	glm::vec2 v = p1 - p2;
	glm::vec2 vOrt(-v.y, v.x);
	glm::vec2 r = center - p2;

	float numerator = glm::dot(vOrt, r);
	float denominator = glm::length(vOrt);

	if ( ((glm::abs(numerator) / denominator) - radius) <= 0)
		return true;
	else
		return false;
}

bool collisionDetection::AABBtoAABB(entity* Box1, entity* Box2, manifold* m)
{

	AABB* box1 = dynamic_cast<AABB*>(Box1->returnType());
	AABB* box2 = dynamic_cast<AABB*>(Box2->returnType());


	bool collision = true;

	if (box1->max.x < box2->min.x || box1->min.x > box2->max.x) return 0;


	if (box1->max.y < box2->min.y || box1->min.y > box2->max.y) return 0;


	//x overlap
	float a_extentx = (box1->max.x - box1->min.x) / 2;
	float b_extentx = (box2->max.x - box2->min.x) / 2;

	glm::vec2 tx = box2->max - box1->max;


	float x_overlap = a_extentx + b_extentx - abs(tx.x);

	//y overlap
	float a_extenty = (box1->max.y - box1->min.y) / 2;
	float b_extenty = (box2->max.y - box2->min.y) / 2;

	glm::vec2 ty = box2->max - box1->max;

	
	float y_overlap = a_extenty + b_extenty - abs(ty.y);



	//contact points
	float c1x = utilities::max(box1->getMin().x, box2->getMin().x);
	float c1y = utilities::max(box1->getMin().y, box2->getMin().y);

	float c2x = utilities::min(box1->getMax().x, box2->getMax().x);
	float c2y = utilities::min(box1->getMax().y, box2->getMax().y);

	glm::vec2 c1 = glm::vec2(c1x, c1y);
	glm::vec2 c2 = glm::vec2(c2x, c2y);

	m->setContactPosition(1, c1);
	m->setContactPosition(1, c2);

	//penetration
	if (x_overlap > y_overlap)
	{
		m->setContactNormal(1, ty.x < 0 ? glm::vec2(1, 0) : glm::vec2(-1, 0));
		m->setContactPenetration(1,x_overlap);
	}
	else
	{
		m->setContactNormal(1, tx.y < 0 ? glm::vec2(0, 1) : glm::vec2(0, -1));
		m->setContactPenetration(1,y_overlap);
	}

	
	
	
	return 1;



}

bool collisionDetection::AABBtoCircle(entity* Box, entity* Circle, manifold* Manifold)
{
	AABB* box = dynamic_cast<AABB*>(Box->returnType());
	boundingCircle* circle = dynamic_cast<boundingCircle*>(Circle->returnType());

	
	glm::vec2 center = circle->getPosition();

	glm::vec2 min = box->getMin();
	glm::vec2 max = box->getMax();

	float right = max.x;
	float left = min.x;
	float bottom = min.y;
	float top = max.y;


	if (center.x > right) center.x = right;
	if (center.x < left) center.x = left;
	if (center.y < bottom) center.y = bottom;
	if (center.y > top) center.y = top;

	float sqdRadius = (circle->getRadius() * circle->getRadius());

	if (utilities::distSqdTwoPoints(center, circle->getPosition()) < sqdRadius)
		return true;
	else
		return false;

	
}


bool collisionDetection::CircleToCircle(entity* C1, entity* C2, manifold* m)
{
	boundingCircle* c1 = dynamic_cast<boundingCircle*>(C1->returnType());
	boundingCircle* c2 = dynamic_cast<boundingCircle*>(C2->returnType());

	float totalRadiusSqd = (c1->getRadius() + c2->getRadius()) * (c1->getRadius() + c2->getRadius());

	if (utilities::distSqdTwoPoints(c1->getPosition(), c2->getPosition()) <= totalRadiusSqd)
	{
		//translation vector between the entities
		glm::vec2 t = c2->getPosition() - c1->getPosition();
		//cummulative radius
		float totalRadius = c1->getRadius() + c2->getRadius();
		// Perform sqrt with pythagorean theorem
		float d = t.length();

		if (d == 0.0f)
		{
			m->setContactPenetration(1, c1->getRadius());
			m->setContactNormal(1, glm::vec2(1, 0));
			m->setContactPosition(1, c1->getPosition());
			m->contactCount = 1;
		}
		else
		{
			m->setContactPenetration(1,totalRadius - d);

			m->setContactNormal(1, t / d);

			m->setContactPosition (1, m->getcontactnormal(1) * c1->getRadius() + c1->getPosition());
			m->contactCount = 1;


		}

		cout << "normal:	" << m->getcontactnormal(1).x << ", " << m->getcontactnormal(1).y << endl;
		cout << "contact point:	" << m->getcontactPosition(1).x << ", " << m->getcontactPosition(1).y << endl;
		cout << "penetration: " << m->getContactPenetration(1) << endl;
		return true;
	}
		
	else
		return false;
}



bool collisionDetection::checkCollisions(entity* player, entity* collidable, manifold* Manifold)
{

	if (dynamic_cast<boundingCircle*>(player->returnType()) != nullptr && dynamic_cast<line*>(collidable->returnType()) != nullptr)
	{
		//cout << "LINE to CIRCLE" << endl;
		return CircleToLine(player, collidable, Manifold);
	}
	if (dynamic_cast<AABB*>(player->returnType()) != nullptr && dynamic_cast<AABB*>(collidable->returnType()) != nullptr)
	{
		//cout << "AABB to AABB" << endl;
		return AABBtoAABB(player, collidable, Manifold);
	}
	if (dynamic_cast<AABB*>(player->returnType()) != nullptr && dynamic_cast<boundingCircle*>(collidable->returnType()) != nullptr)
	{
		//cout << "AABB to CIRCLE" << endl;
		return AABBtoCircle(player, collidable, Manifold);
	}
	if (dynamic_cast<boundingCircle*>(player->returnType()) != nullptr && dynamic_cast<boundingCircle*>(collidable->returnType()) != nullptr)
	{
		//cout << "AABB to CIRCLE" << endl;
		return CircleToCircle(player, collidable, Manifold);
	}

	
	else
	return 0;
}