#pragma once
#include "Shape.h"
#include "LoadShape.h"
enum Color {RED, GREEN};

class TrafficLight
{
	private:
	COORD m_position;;
	Shape* m_shape[2];
	int m_lastTime;
	int m_greenDuration, m_redDuration;
	Color m_color;

	public:
	TrafficLight();

	TrafficLight(int greenDuration, int redDuration): m_color{ RED }, m_lastTime{0}, m_greenDuration{greenDuration}, m_redDuration{redDuration} {}

	void setGreenDuration(int greenDuration) {
		m_greenDuration = greenDuration;
	}

	void setRedDuration(int redDuration) {
		m_redDuration = redDuration;
	}

	void setPos(const COORD &pos);
	void render(int offset = 0);
	void update();
	COORD getPos();
	bool isRed();
	void setRedLight();
	void setGreenLight();
};

