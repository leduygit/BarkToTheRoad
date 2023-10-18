#pragma once
#include "Lane.h"
#include "GrassObstacleFactory.h"
class GrassLane : public Lane
{
public:
	GrassLane() = default;
	GrassLane(COORD pos, std::string file_name);

	void spawnObstacle(int num);
	using Lane::render;
	void renderAll();
private:
};

