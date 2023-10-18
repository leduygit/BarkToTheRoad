#include "Lane.h"

void Lane::render()
{
	for (int i = 0; i < 10; i++) {
		m_shape.render(m_position.X + 90 * i, m_position.Y);
	}

	for (auto obs : m_obs)
		obs->render();
}

void Lane::addObstacle()
{
	Obstacle* newObstacle = m_fact->createObstacle(m_position);
	if (newObstacle) 
	{
		if (m_obs.empty() || newObstacle->isCollison(*m_obs.back()) == false) // if there's no Collison with the newest Obstacle
			m_obs.push_back(newObstacle);
		else
			delete newObstacle;
	}
}

void Lane::moveObstacle()
{
	for (auto obs : m_obs)
	{
		COORD pos = obs->getPos();
		SHORT x = 100; 
		obs->move({ pos.X + x, pos.Y });
	}
}

