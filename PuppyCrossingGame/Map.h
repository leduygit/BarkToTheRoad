#pragma once
#include "LaneFactory.h"
class Map
{
private:
	int m_lane_number{ 7 };
	Lane* m_lane[10];
	static LaneFactory* m_fact;
public:
	Map() = default;
	Map(LaneFactory* fact);
	bool checkCollision(Entity& e);
	void moveObstacle();
	void addObstacle();

	void render();
	void addLane();
};

