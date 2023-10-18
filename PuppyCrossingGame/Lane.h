#pragma once
#include "ObstacleFactory.h"
#include "BusObstacle.h"
#include "vector"
class Lane
{
protected:
	COORD m_position{};
	Shape m_shape{};
	ObstacleFactory* m_fact{};
	int m_obsSize = 0;
	Obstacle* m_obs[10];
	Obstacle busModel;
public:
	Lane() = default;
	Lane(COORD pos, std::string file_name, ObstacleFactory* fact);
	void render();
	void addObstacle();
	void moveObstacle();
};

