#include "TrainObstacle.h"
TrainObstacle::TrainObstacle(COORD pos)
{
	m_shape = new Shape("image/train_right.txt");
	m_position = pos;
}