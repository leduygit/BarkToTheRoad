#pragma once
#include "Lane.h"
class RailLane: public Lane
{
public:
	RailLane() = default;
	RailLane(COORD pos, std::string file_name, ObstacleFactory* fact): Lane(pos, file_name, fact) {}
};

