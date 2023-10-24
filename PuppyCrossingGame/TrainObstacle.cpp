#include "TrainObstacle.h"

TrainObstacle::TrainObstacle(COORD pos)
{
	m_shape = MyShape[TRAIN_RIGHT];
	m_position = pos;
}