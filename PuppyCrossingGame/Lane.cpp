#include "Lane.h"

constexpr int NUM_SQUARE = 14;


Lane::Lane(const COORD &pos) :
	m_position{ pos }
{
	m_shape = *MyShape[ROAD];
	if (randomInt(0, 100) % 2)
		m_light.setPos({ 300, m_position.Y });
	else
		m_light.setPos({ 811, m_position.Y });
	m_light.setGreenDuration(randomInt(1000, 8000));
	m_light.setRedDuration(randomInt(5000, 5000));
}

void Lane::render(int offset)
{
	int x = 0;
	for (int i = 0; i < NUM_SQUARE; i++) {
		m_shape.render(x, m_position.Y - offset);
		x += 90;
	}

	for (auto obs: m_obs) {
		obs->render(offset);
	}

	if (isRiverLane() == false) m_light.render(offset);
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

	for (int i = 0; i < m_obs.size(); ++i)
	{
		Obstacle* obs = m_obs[i];
		COORD pos = obs->getPos();
		SHORT x = 50;
		COORD lightPos = m_light.getPos();
		if (isRed == false) obs->move({ static_cast<short>(pos.X + x), pos.Y });
		else {
			// if go pass the light
			if (pos.X > lightPos.X + 10) {
				obs->move({ static_cast<short>(pos.X + x), pos.Y });
			}
			
			// if behind the light
		
			if (pos.X <= lightPos.X - 90) {
				if (pos.X + x <= lightPos.X - 90)
					obs->move({ static_cast<short>(pos.X + x), pos.Y });
				else
					obs->stopMoving();
				if (i > 0)
				{
					auto preObs = m_obs[i - 1];
					COORD curPos = preObs->getPos();
					COORD newPos = { curPos.X - 20, curPos.Y };
					preObs->setPos(newPos);
					if (preObs->isCollison(*obs)) obs->stopMoving();
					preObs->setPos(curPos);
				}
				
			}
		}
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

void Lane::setPos(const COORD& pos)
{
	m_position = pos;
	for (auto obs : m_obs)
	{
		COORD obsPos = obs->getPos();
		obs->setPos({obsPos.X, pos.Y});
	}
	
	COORD lightPos = m_light.getPos();
	m_light.setPos({ lightPos.X, pos.Y });
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

