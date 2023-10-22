#include "GrassLane.h"

GrassLane::GrassLane(COORD pos)
{
	m_position = pos;
	m_fact = new GrassObstacleFactory();
	int rand = randomInt(0, 9);
	if (rand % 2) {
		m_shape = Shape("image/grass_lane.txt");
	}
	else {
		m_shape = Shape("image/grass_lane_1.txt");
	}
	spawnObstacle();
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
		m_obs.push_back(fac.createObstacle({ static_cast<short>(m_position.X + 90 * rand), m_position.Y}));
		num--;
	}
}