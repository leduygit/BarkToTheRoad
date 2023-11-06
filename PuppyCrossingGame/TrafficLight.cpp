#include "TrafficLight.h"

TrafficLight::TrafficLight()
{
	m_shape[RED_LIGHT] = MyShape[GRASS_0];
	m_shape[GREEN_LIGHT] = MyShape[DOG_JUMP_1];
	m_color = GREEN_LIGHT;
	m_redDuration = 3000;
	m_greenDuration = 5000;
	m_lastTime = GetTickCount();
}

void TrafficLight::setPos(const COORD& pos)
{
	m_position = { pos.X + 100, pos.Y };
}

void TrafficLight::render()
{
	// render light
	m_shape[m_color]->render(m_position.X, m_position.Y);
}

void TrafficLight::update()
{
	// update light color
	int current_time = GetTickCount();
	int duration = current_time - m_lastTime;
	int desireDuration = (m_color == RED_LIGHT) ? m_redDuration : m_greenDuration;
	if (duration >= desireDuration) {
		m_color = (m_color == RED_LIGHT) ? GREEN_LIGHT : RED_LIGHT;
		m_lastTime = current_time;
	}
}

COORD TrafficLight::getPos()
{
	return m_position;
}

bool TrafficLight::isRed()
{
	return (m_color == RED_LIGHT);
}
