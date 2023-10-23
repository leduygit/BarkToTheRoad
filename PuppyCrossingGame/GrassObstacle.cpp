#include "GrassObstacle.h"

GrassObstacle::GrassObstacle(COORD pos) 
{
	int random = rand() % 3;
	if (random == 1) {
		m_shape = new Shape("image/stone.txt");
	}
	else if (random == 2) {
		m_shape = new Shape("image/stones1.txt");
	}
	else {
		m_shape = new Shape("image/bush2.txt");
	}
	m_position = pos;
}