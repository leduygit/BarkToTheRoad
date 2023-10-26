#pragma once
#include "ObstacleFactory.h"

class GrassObstacleFactory : public ObstacleFactory {
public:
	Obstacle* createObstacle(COORD pos) override;
};