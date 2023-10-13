#pragma once
#include "Obstacle.h"
class ObstacleFactory
{
public:
	virtual Obstacle* createObstacle();
};

