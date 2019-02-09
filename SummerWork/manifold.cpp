#include "manifold.h"


void manifold::setContactPosition(int contact, glm::vec2 pos)
{
	contacts[contact].position = pos;
}



void manifold::setContactNormal(int contact, glm::vec2 normal)
{
	contacts[contact].normal = normal;
}



void manifold::setContactPenetration(int contact, float pen)
{
	contacts[contact].penetration = pen;
}