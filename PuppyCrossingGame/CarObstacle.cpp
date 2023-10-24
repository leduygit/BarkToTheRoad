#include "CarObstacle.h"



CarObstacle::CarObstacle(COORD pos)
{
	m_shape = MyShape[CAR_RIGHT];
	m_position = pos;
}

