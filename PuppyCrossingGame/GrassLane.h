#pragma once
#include "Lane.h"
class GrassLane : public Lane
{
public:
	GrassLane() = default;
	GrassLane(const COORD &pos);
	void addObstacle() override;
	void moveObstacle() override;
	void spawnObstacle();
	void render() override;
	bool isStaticLane() override {
		return false;
	}
	bool checkCollision(Character& e) override {
		if (!e.isStanding()) return false;
		for (auto obstacle : m_obs)
		{
			if (obstacle->isCollison(e))
				return true;
		}
		return false;
	}
private:
	Shape m_lanes[14];
};



