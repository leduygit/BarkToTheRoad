#pragma once
#include "ObstacleFactory.h"
#include "vector"
class Lane
{
private:
	COORD m_position;
	Shape m_shape;
	ObstacleFactory* m_fact;
	std::vector<Obstacle*> m_obs;
public:
	void render();
	// void moveObstacle();
};

