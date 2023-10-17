#pragma once
#include "Lane.h"

class LaneFactory
{
public:
	virtual Lane* createLane(COORD pos) = 0;
private:
};

