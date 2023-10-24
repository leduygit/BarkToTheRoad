#pragma once
#include "Entity.h"

class Character : public Entity
{
private:
	bool isDead;
	bool m_is_standing{ true };
public:
	Character() = default;
	Character(COORD pos, Shape* s) : Entity(pos, s) {}
	void Bark();
	bool isFinish(); // isDead checking
	bool isStanding() const;
	void render();
	void move(COORD pos);
	COORD getPos();
};

