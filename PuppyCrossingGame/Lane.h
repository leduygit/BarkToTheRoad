#pragma once
#include "ObstacleFactory.h"
#include "vector"
#include "LoadShape.h"

class Lane
{
protected:
	COORD m_position{};
	int m_obsSize = 0;
	std::vector<Obstacle*> m_obs;
	Obstacle busModel;
public:
	ObstacleFactory* m_fact;
	Shape m_shape;


	Lane() = default;
	Lane(COORD pos);
	virtual void render();
	virtual void addObstacle();
	virtual void moveObstacle();
};

