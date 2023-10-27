#include "Lane.h"


Lane::Lane(COORD pos) :
	m_position{ pos }
{
	busModel = BusObstacle(m_position);
	m_shape = *MyShape[ROAD];
}

void Lane::render()
{
	int x = 0;
	for (int i = 0; i < 14; i++) {
		m_shape.render(x, m_position.Y);
		x += 90;
	}

	for (auto obs: m_obs) {
		obs->render();
	}
}

void Lane::addObstacle()
{
	int x = randomInt(0, 1000);
	if (x < 600) return;
	if (m_obs.size() >= 5) return;
	if (m_obs.size() != 0 && busModel.isCollison(*m_obs[m_obs.size() - 1]) == true) return;

	// if there's no Collison with the newest Obstacle
	Obstacle* newObstacle = m_fact->createObstacle(m_position);
	if (newObstacle) 
		m_obs.push_back(newObstacle);
}

void Lane::removeObstacle()
{
	int sz = m_obs.size();
	for (int i = sz - 1; i >= 0; --i)
	{
		COORD pos = m_obs[i]->getPos();
		if (isInside(pos) == false)
		{
			std::swap(m_obs.back(), m_obs[i]);
			if (m_obs.back()) {
				delete m_obs.back();
				m_obs.pop_back();
			}
		}
	}
}

void Lane::moveObstacle()
{
	for (auto obs : m_obs)
	{
		COORD pos = obs->getPos();
		SHORT x = 100; 
		obs->move({ static_cast<short>(pos.X + x), pos.Y });
	}
}

bool Lane::checkCollision(Character& e)
{
	for (auto obstacle : m_obs)
	{
		if (obstacle->isCollison(e))
			return true;
	}
	return false;
}

