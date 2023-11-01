#pragma once
#include "Lane.h"
#include "Character.h"
class RiverLane : public Lane
{
public:
	RiverLane() = default;
	RiverLane(COORD pos);
	void moveObstacle(Character& c) override;
	bool checkCollision(Character& e) override;
private:
	Shape m_lanes[14];
};

