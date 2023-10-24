#include "GrassObstacle.h"


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
}