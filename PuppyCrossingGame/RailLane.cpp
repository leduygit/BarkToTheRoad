#include "RailLane.h"
#include "Sound.h"
void RailLane::addObstacle()
{
	if (m_obs.size() >= 1) return;
	int x = randomInt(0, 1000);
	if (x < 950) return;
	Obstacle* newObstacle = nullptr;
	if (direction > 0)
	{
		newObstacle = m_fact->createObstacle(m_position);
	}
	else {
		newObstacle = m_fact->createObstacle({ static_cast<short>(m_position.X + 1400), m_position.Y });
	}
	if (newObstacle == nullptr) return;
	m_obs.push_back(newObstacle);
}

void RailLane::moveObstacle()
{
	if (!m_light.isRed() && m_obs.size() == 1) 
	{
		m_light.setRedLight();
		if (randomInt(0, 1000) <= 500) {
			SoundTrack::playSound(L"resources/sound/train_sound.wav", L"alias_train_horn");
		}
	}
	else if (m_light.isRed() && m_obs.size() == 0) m_light.setGreenLight();
	
	for (auto obs : m_obs) 
	{
		COORD pos = obs->getPos();
		SHORT x = 50 * direction;
		obs->move({ static_cast<short>(pos.X + x), pos.Y });
	}
}
