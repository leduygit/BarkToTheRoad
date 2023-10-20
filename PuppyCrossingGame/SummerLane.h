#pragma once
#include "Lane.h"
class SummerLane: public Lane
{
public:
	SummerLane() = default;
	SummerLane(COORD pos, std::string file_name, ObstacleFactory* fact) {}
};

