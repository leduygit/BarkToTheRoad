#include "RailObstacleFactory.h"

Obstacle* RailObstacleFactory::createObstacle(COORD pos) {
	return new TrainObstacle(pos);
}