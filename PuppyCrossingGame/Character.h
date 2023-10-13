#pragma once
#include "Entity.h"

class Character : public Entity
{
private:
	bool isDead;
public:
	Character();
	~Character();
	void Bark();
	bool isFinish(); // isDead checking
};

