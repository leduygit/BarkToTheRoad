#include "Lane.h"

constexpr int NUM_SQUARE = 14;


Lane::Lane(const COORD &pos) :
	m_position{ pos }
{
	m_shape = *MyShape[ROAD];
	m_light.setPos(m_position);
}

void Lane::render()
{
	int x = 0;
	for (int i = 0; i < NUM_SQUARE; i++) {
		m_shape.render(x, m_position.Y);
		x += 90;
	}

	for (auto obs: m_obs) {
		obs->render();
	}

	if (isRiverLane() == false) m_light.render();
}

void Lane::addObstacle()
{
	int x = randomInt(0, 1000);
	if (x < 600) return;
	if (m_obs.size() >= 5) return;
	Obstacle* newObstacle = m_fact->createObstacle(m_position);
	if (newObstacle == nullptr) return;
	if (m_obs.size() == 0 || newObstacle->isCollison(*m_obs.back()) == false)
		m_obs.push_back(newObstacle);
	else
		delete newObstacle;
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
		else break;
	}
}

void Lane::moveObstacle()
{
	m_light.update();

	bool isRed = m_light.isRed();

	for (auto obs : m_obs)
	{
		COORD pos = obs->getPos();
		SHORT x = 50;
		if (isRed == false) obs->move({ static_cast<short>(pos.X + x), pos.Y });
		else obs->stopMoving();
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

COORD Lane::getCollision(Character& c)
{
	for (auto obstacle : m_obs)
	{
		if (obstacle->isCollison(c))
			return obstacle->getPos();
	}
	return { -1, -1 };
}

