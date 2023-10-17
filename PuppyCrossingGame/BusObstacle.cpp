#include "BusObstacle.h"

BusObstacle::BusObstacle(COORD pos)
{
	m_shape = new Shape("image/dog_stay_1.txt");
	m_position = pos;
}
