#pragma once
#include "Lane.h"
#include "GrassObstacleFactory.h"
#include <string>
#include <time.h>
class GrassLane : public Lane
{
public:
	GrassLane() = default;
	GrassLane(COORD pos);
	void addObstacle() override;
	void moveObstacle() override;
	void spawnObstacle();
	void render() override;
private:
	Shape m_lanes[14];
};



