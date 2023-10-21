#pragma once
#include "ObstacleFactory.h"
#include "BusObstacle.h"
#include "vector"
class Lane
{
protected:
	COORD m_position{};
	static ObstacleFactory* m_fact;
	static Shape m_shape;
	int m_obsSize = 0;
	std::vector<Obstacle*> m_obs;
	Obstacle busModel;
public:


	Lane() = default;
	Lane(COORD pos);
	void render();
	void addObstacle();
	void moveObstacle();
};

