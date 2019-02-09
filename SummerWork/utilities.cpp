#include "utilities.h"


float utilities::distSqdTwoPoints(const glm::vec2 p1, const glm::vec2 p2)
{
	return	((p2.x - p1.x) * (p2.x - p1.x)) + ((p2.y - p1.y) * (p2.y - p1.y));
}

float utilities::max(float a, float b)
{
	if (a > b)
		return a;
	else
		return b;
}

float utilities::min(float a, float b)
{
	if (a < b)
		return a;
	else
		return b;
}