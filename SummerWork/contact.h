#pragma once
#include <glm/glm.hpp>

class contact
{
public:
	contact(){}


	glm::vec2 position;
	glm::vec2 normal;
	float penetration;
private:
	

};