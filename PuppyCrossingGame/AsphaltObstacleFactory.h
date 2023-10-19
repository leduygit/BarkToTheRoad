#pragma once
#include "ObstacleFactory.h"
#include "CarObstacle.h"
#include "BusObstacle.h"
class AsphaltObstacleFactory: public ObstacleFactory
{
public:
	Obstacle* createObstacle(COORD pos) override;
};

