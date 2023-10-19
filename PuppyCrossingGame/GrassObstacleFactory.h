#pragma once
#include "ObstacleFactory.h"
#include "GrassObstacle.h"

class GrassObstacleFactory : public ObstacleFactory {
public:
	Obstacle* createObstacle(COORD pos) override;
};