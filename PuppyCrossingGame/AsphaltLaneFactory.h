#pragma once
#include "LaneFactory.h"
#include "AsphaltLane.h"
#include "AsphaltObstacleFactory.h"
class AsphaltLaneFactory : public LaneFactory
{
public:
	Lane* createLane(COORD pos) override;
};

