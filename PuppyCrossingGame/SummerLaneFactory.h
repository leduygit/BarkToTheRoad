#pragma once
#include "LaneFactory.h"
#include "Lane.h"
#include "SummerLane.h"
class SummerLaneFactory: LaneFactory
{
public:
	Lane* createLane(COORD pos, std::string file_name, ObstacleFactory* fact);
};

