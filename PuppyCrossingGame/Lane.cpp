#include "Lane.h"

Lane::Lane(COORD pos) :
	m_position{ pos }
{
	busModel = BusObstacle(m_position);
	m_shape = Shape("image/road.txt");
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

	for (auto obs : m_obs)
		obs->render();
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

void Lane::moveObstacle()
{
	for (auto obs : m_obs)
	{
		COORD pos = obs->getPos();
		SHORT x = 100; 
		obs->move({ static_cast<short>(pos.X + x), pos.Y });
	}
}

