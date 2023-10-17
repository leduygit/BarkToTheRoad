#pragma once
#include "Obstacle.h"
class TrainObstacle: Obstacle
{
public:
	TrainObstacle(COORD pos) {
		m_shape = new Shape("image/dog_stay_1.txt");
		m_position = pos;
	}

	void render() {
		Obstacle::render();
	}
private:
};

