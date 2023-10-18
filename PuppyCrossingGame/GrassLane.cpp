#include "GrassLane.h"

GrassLane::GrassLane(COORD pos, std::string file_name)
{
	m_position = pos;
	m_shape = Shape{ file_name };
}

void GrassLane::spawnObstacle(int num)
{
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

void GrassLane::renderAll()
{
	Lane::render();
	for (auto x : m_obs)
	{
		x->render();
	}
}
