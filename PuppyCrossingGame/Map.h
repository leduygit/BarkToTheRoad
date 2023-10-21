#pragma once
#include "LaneFactory.h"
class Map
{
private:
	Lane* m_lane[10];
	static LaneFactory* m_fact;
public:
	Map() = default;
	Map(LaneFactory* fact);
	bool checkCollision(Entity& e);
	void render();
	void addLane();
};

