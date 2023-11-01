#pragma once
#include "Lane.h"
class RailLane: public Lane
{
public:
	RailLane() = default;
	RailLane(const COORD &pos): Lane(pos) {
		m_fact = new RailObstacleFactory();
		m_shape = *MyShape[RAIL];
	}
};



