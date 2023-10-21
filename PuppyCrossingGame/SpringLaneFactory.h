#pragma once
#include "LaneFactory.h"
#include "Lane.h"
#include "SummerLane.h"
#include "AsphaltLane.h"
#include "GrassLane.h"
#include "RailLane.h"

class SpringLaneFactory
{
public:
	Lane* createLane(COORD pos, std::string file_name, ObstacleFactory* fact);
};

