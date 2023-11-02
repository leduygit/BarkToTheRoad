#include "GrassLane.h"


GrassLane::GrassLane(const COORD &pos)
{
	m_position = pos;
	m_fact = new GrassObstacleFactory();
	m_shape = *MyShape[GRASS_0];
	for (int i = 0; i < 14; i++) {
		int rand = randomInt(1, 100);
		if (rand % 2)
			m_lanes[i] = *MyShape[GRASS_0];
		else {
			rand = randomInt(1, 4);
			m_lanes[i] = *MyShape[rand + GRASS_0];
		}
	}
	spawnObstacle();
}

void GrassLane::addObstacle()
{
	
}

void GrassLane::render()
{
	for (int i = 0; i < 14; i++) {
		m_lanes[i].render(90 * i, m_position.Y);
	}

	for (auto obs : m_obs) {
		obs->render();
	}
}

void GrassLane::moveObstacle()
{
	return;
}

void GrassLane::spawnObstacle()
{
	int num = randomInt(1, 4);
	bool obs_array[14]{};
	GrassObstacleFactory fac;
	while (num)
	{
		int rand = randomInt(0, 13);
		if (obs_array[rand]) continue;
		obs_array[rand] = 1;
		m_obs.push_back(fac.createObstacle({ static_cast<short>(m_position.X + 90 * rand), m_position.Y }));
		num--;
	}
}
