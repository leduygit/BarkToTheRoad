#pragma once
#include "Lane.h"
#include "GrassObstacleFactory.h"
class GrassLane : public Lane
{
public:
	GrassLane() = default;
	GrassLane(COORD pos);

	void spawnObstacle();
	using Lane::render;
private:
};



