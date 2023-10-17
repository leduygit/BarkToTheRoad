#pragma once
#include "Entity.h"
class Obstacle : public Entity
{
private:
	int a = 5;
public:
	void move();
};