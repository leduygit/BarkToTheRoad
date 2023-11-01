#include "RiverLane.h"

RiverLane::RiverLane(COORD pos) : 
	Lane(pos)
{
	m_fact = new RiverObstacleFactory();
	m_shape = *MyShape[BUSH_2];
}

void RiverLane::moveObstacle(Character& c)
{
	for (auto obs : m_obs)
	{
		COORD pos = obs->getPos();
		SHORT distance = 90;
		obs->move({ static_cast<short>(pos.X + distance), pos.Y });
		if (c.isCollison(*obs) && c.isStanding())
		{
			COORD pos = c.getPos();
			SHORT distance = 90;
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
