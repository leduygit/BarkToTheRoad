#pragma once
#include "Obstacle.h"
class TrainObstacle: public Obstacle
{
public:
	TrainObstacle() = default;
	TrainObstacle(COORD pos) {
		m_shape = new Shape("image/dog_stay_1.txt");
		m_position = pos;
	}
private:
};

