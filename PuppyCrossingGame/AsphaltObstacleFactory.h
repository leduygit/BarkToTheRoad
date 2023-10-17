#pragma once
#include "ObstacleFactory.h"
#include "CarObstacle.h"
#include "BusObstacle.h"
class AsphaltObstacleFactory: ObstacleFactory
{
public:
	Obstacle* createObstacle(COORD pos) override;
};

