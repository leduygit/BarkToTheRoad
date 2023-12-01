#include "RiverLane.h"

RiverLane::RiverLane(const COORD &pos) : 
	Lane(pos)
{
	m_fact = new RiverObstacleFactory();
	m_shape = *MyShape[RIVER];
	m_shapeIndex = RIVER;
	m_factoryIndex = RiverFactory;
}

void RiverLane::moveObstacle(Character& c)
{
	for (auto obs : m_obs)
	{
		COORD pos = obs->getPos();
		SHORT distance = 90 * direction;
		obs->move({ static_cast<short>(pos.X + distance), pos.Y });
		if (c.isCollison(*obs) && c.isStanding())
		{
			COORD pos = c.getPos();
			SHORT distance = 90 * direction;
			c.moveInRaft({ static_cast<short>(pos.X + distance), pos.Y });
		}
	}
}

bool RiverLane::checkCollision(Character& e)
{
	COORD characterPos = e.getPos();
	if (characterPos.Y + 90 <= m_position.Y) return false;
	if (m_position.Y + 90 <= characterPos.Y) return false;

	for (auto obs : m_obs)
	{
		if (e.isCollison(*obs)) return false;
	}
	return true;
}

bool RiverLane::spawnRate()
{
	int x = randomInt(1, 1000);
	if (x <= 500)
		return true;
	return false;
}

bool RiverLane::isRiverLane()
{
	return true;
}

void RiverLane::addObstacle()
{
	if (!spawnRate()) return;
	Obstacle* newObstacle = nullptr;
	if (direction > 0)
	{
		newObstacle = m_fact->createObstacle(m_position);
	}
	else {
		newObstacle = m_fact->createObstacle({ static_cast<short>(m_position.X + 1280), m_position.Y });
	}
	if (newObstacle == nullptr) return;
	if (m_obs.size() == 0 || newObstacle->isCollison(*m_obs.back()) == false)
		m_obs.push_back(newObstacle);
	else
		delete newObstacle;
}
