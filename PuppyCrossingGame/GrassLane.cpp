#include "GrassLane.h"

GrassLane::GrassLane(COORD pos)
{
	m_position = pos;
	m_fact = new GrassObstacleFactory();
	m_shape = Shape("image/grass_0.txt");
	for (int i = 0; i < 14; i++) {
		int rand = randomInt(1, 100);
		if (rand % 2)
			m_lanes[i] = Shape("image/grass_0.txt");
		else {
			rand = randomInt(0, 3);
			m_lanes[i] = Shape("image/grass_" + std::to_string(rand + 1) + ".txt");
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
