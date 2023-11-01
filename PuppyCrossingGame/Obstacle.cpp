#include "Obstacle.h"

BusObstacle::BusObstacle(COORD pos)
{
	m_shape = MyShape[CAR_RIGHT];
	m_position = pos;
	setRate(Global::HIGH_SPEED);
}

CarObstacle::CarObstacle(COORD pos)
{
	m_shape = MyShape[CAR_RIGHT];
	m_position = pos;
	setRate(Global::HIGH_SPEED);
}

GrassObstacle::GrassObstacle(COORD pos)
{
	int random = rand() % 3;
	if (random == 1) {
		m_shape = MyShape[STONE];
	}
	else if (random == 2) {
		m_shape = MyShape[STONE_1];
	}
	else {
		m_shape = MyShape[BUSH_2];
	}
	m_position = pos;
	m_type = STANDING;
}

TrainObstacle::TrainObstacle(COORD pos)
{
	m_shape = MyShape[TRAIN_RIGHT];
	m_position = pos;
	setRate(Global::MEDIUM_SPEED);
}

RaftObstacle::RaftObstacle(COORD pos)
{
	m_shape = MyShape[ROAD];
	m_position = pos;
}
