#pragma once
#include "LaneFactory.h"
#include "Lane.h"
#include "SummerLane.h"
class SummerLaneFactory: public LaneFactory
{
public:
	Lane* createLane(COORD pos);
};

