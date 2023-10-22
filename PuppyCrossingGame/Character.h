#pragma once
#include "Entity.h"

class Character : public Entity
{
private:
	bool isDead;
public:
	Character() = default;
	Character(COORD pos, Shape* s) : Entity(pos, s) {}
	void Bark();
	bool isFinish(); // isDead checking
	COORD getPos();
};

