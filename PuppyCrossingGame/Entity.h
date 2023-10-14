#pragma once
#include "windows.h"
#include "Shape.h"
class Entity
{
private:
	COORD m_position;
	Shape m_shape;
	int m_width;
	int m_height;
public:
	Entity() = default;
	Entity(COORD pos, Shape s) : m_position{ pos }, m_shape{ s } {}
	void render();
	void move(COORD pos);
	// virtual bool isImpact(const Entity& obj) const;
};