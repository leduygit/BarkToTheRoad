#include "RailLane.h"

void RailLane::addObstacle()
{
	int x = randomInt(0, 1000);
	if (x < 850) return;
	if (m_obs.size() >= 1) return;
	Obstacle* newObstacle = m_fact->createObstacle(m_position);
	if (newObstacle == nullptr) return;
	m_obs.push_back(newObstacle);
}

void RailLane::moveObstacle()
{
	if (!m_light.isRed() && m_obs.size() == 1) m_light.setRedLight();
	else if (m_light.isRed() && m_obs.size() == 0) m_light.setGreenLight();
	
	for (auto obs : m_obs) 
	{
		COORD pos = obs->getPos();
		SHORT x = 50;
		obs->move({ static_cast<short>(pos.X + x), pos.Y });
	}
}
