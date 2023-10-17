#pragma once
#include "ObstacleFactory.h"
#include "TrainObstacle.h"

class RailObstacleFactory: public ObstacleFactory {
public:
	Obstacle* createObstacle() override;
};