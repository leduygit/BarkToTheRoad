#pragma once
#include "Obstacle.h"
#include <time.h>

int randomInt(int l, int r);

class ObstacleFactory
{
public:
	virtual Obstacle* createObstacle(COORD pos) = 0;
};

