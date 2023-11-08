#include "TrafficLight.h"

TrafficLight::TrafficLight()
{
	m_shape[RED] = MyShape[ShapeIndex::RED_LIGHT];
	m_shape[GREEN] = MyShape[ShapeIndex::GREEN_LIGHT];
	m_color = GREEN;
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
	int desireDuration = (m_color == RED) ? m_redDuration : m_greenDuration;
	if (duration >= desireDuration) {
		m_color = (m_color == RED) ? GREEN : RED;
		m_lastTime = current_time;
	}
}

COORD TrafficLight::getPos()
{
	return m_position;
}

bool TrafficLight::isRed()
{
	return (m_color == RED);
}

void TrafficLight::setRedLight()
{
	m_color = RED;
}

void TrafficLight::setGreenLight()
{
	m_color = GREEN;
}