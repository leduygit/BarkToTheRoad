#pragma once
#include "ObstacleFactory.h"
#include "vector"
class Lane
{
protected:
	COORD m_position{};
	Shape m_shape{};
	ObstacleFactory* m_fact{};
	std::vector<Obstacle*> m_obs{};
public:
	Lane() = default;
	Lane(COORD pos, std::string file_name) : m_position{ pos }, m_shape{ file_name } {}
	void render();
	// void moveObstacle();
};

