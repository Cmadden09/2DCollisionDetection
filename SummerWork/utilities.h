#pragma once
#include <glm/glm.hpp>

class utilities
{
public:

	static float distSqdTwoPoints(const glm::vec2 p1, const glm::vec2 p2);
	static float max(float, float);
	static float min(float, float);
private:
	utilities() {}
};