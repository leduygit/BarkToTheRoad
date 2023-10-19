#include "GrassObstacleFactory.h"

Obstacle* GrassObstacleFactory::createObstacle(COORD pos) {
	return new GrassObstacle(pos);
}