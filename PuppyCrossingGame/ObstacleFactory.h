#pragma once
#include "Obstacle.h"
#include <time.h>

int randomInt(int l, int r);

class ObstacleFactory
{
public:
	virtual Obstacle* createObstacle(const COORD &pos) = 0;
};

class AsphaltObstacleFactory : public ObstacleFactory
{
public:
	Obstacle* createObstacle(const COORD &pos) override;
};

class GrassObstacleFactory : public ObstacleFactory {
public:
	Obstacle* createObstacle(const COORD &pos) override;
};


class RailObstacleFactory : public ObstacleFactory {
public:
	Obstacle* createObstacle(const COORD &pos) override;
};

class RiverObstacleFactory : public ObstacleFactory {
public:
	Obstacle* createObstacle(const COORD &pos) override;
};



