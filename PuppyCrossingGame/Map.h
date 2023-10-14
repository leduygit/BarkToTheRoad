#pragma once
#include "Lane.h"
class Map
{
private:
	Lane m_lane[10];
	
public:
	bool checkCollision(Entity& e);
	void render();
	virtual Lane* createLane();
};

