#pragma once
#include "entity.h"
#include "contact.h"

class manifold
{
public:
	manifold(){}

	void setContactPosition(int contact, glm::vec2 pos);
	void setContactNormal(int contact, glm::vec2 normal);
	void setContactPenetration(int contact, float pen);

	glm::vec2 getcontactPosition(int contact) { return contacts[contact].position; }
	glm::vec2 getcontactnormal(int contact) { return contacts[contact].normal; }
	float getContactPenetration(int contact) { return contacts[contact].penetration; }

	contact contacts[2];
	unsigned contactCount;
	entity* A;
	entity* B;
private:
	

};