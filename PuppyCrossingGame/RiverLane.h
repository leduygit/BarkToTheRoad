#pragma once
#include "Lane.h"
#include "Character.h"
class RiverLane : public Lane
{
public:
	RiverLane() = default;
	RiverLane(const COORD &pos);
	void moveObstacle(Character& c) override;
	bool checkCollision(Character& e) override;
	bool spawnRate() override;
	bool isRiverLane() override;
	void addObstacle() override;
private:
	Shape m_lanes[14];
};

