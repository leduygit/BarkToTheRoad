#include "GrassObstacle.h"

GrassObstacle::GrassObstacle(COORD pos) {
		m_shape = new Shape("image/bush.txt");
		m_position = pos;
	}