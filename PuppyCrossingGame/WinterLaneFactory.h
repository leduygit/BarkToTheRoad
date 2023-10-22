#pragma once
#include "LaneFactory.h"
#include "Lane.h"
#include "SummerLane.h"
#include "AsphaltLane.h"
#include "GrassLane.h"
#include "RailLane.h"

class WinterLaneFactory
{
public:
	Lane* createLane(COORD pos);
};

