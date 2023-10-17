#include "RailObstacleFactory.h"

Obstacle* RailObstacleFactory::createObstacle() {
	return new TrainObstacle();
}