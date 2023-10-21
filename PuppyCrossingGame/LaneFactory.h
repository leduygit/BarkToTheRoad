#pragma once
#include "Lane.h"

class LaneFactory
{
public:
	//	Lane(COORD pos, std::string file_name, ObstacleFactory* fact);
	virtual Lane* createLane(COORD pos) = 0;
private:
};

