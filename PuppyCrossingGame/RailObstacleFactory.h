#pragma once
#include "ObstacleFactory.h"

class RailObstacleFactory: public ObstacleFactory {
public:
	Obstacle* createObstacle(COORD pos) override;
};