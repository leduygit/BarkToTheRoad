#pragma once
#include "Lane.h"
class GrassLane : public Lane
{
public:
	GrassLane() = default;
	GrassLane(COORD pos);
	void addObstacle() override;
	void moveObstacle() override;
	void spawnObstacle();
	void render() override;
	bool isValid() override {
		return false;
	}
private:
	Shape m_lanes[14];
};



