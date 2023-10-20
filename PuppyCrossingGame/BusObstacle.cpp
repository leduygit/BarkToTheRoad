#include "BusObstacle.h"

BusObstacle::BusObstacle(COORD pos)
{
	m_shape = new Shape("image/cow_right.txt");
	m_position = pos;
}
