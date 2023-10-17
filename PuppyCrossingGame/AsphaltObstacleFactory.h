#pragma once
#include "ObstacleFactory.h"
class AsphaltObstacleFactory: ObstacleFactory
{
public:
	Obstacle* createObstacle() override {
		return nullptr;
	}
};

