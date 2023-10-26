#pragma once
#include "Lane.h"
class RailLane: public Lane
{
public:
	RailLane() = default;
	RailLane(COORD pos): Lane(pos) {
		m_fact = new RailObstacleFactory();
		m_shape = Shape("image/railway_lane.txt");
	}
};



