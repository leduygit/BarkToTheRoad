#pragma once
#include "windows.h"
#include "Shape.h"
class Entity
{
private:
	COORD m_position;
	COORD m_new_position;
	Shape* m_shape;
	//int m_width;
	//int m_height;
	int m_velo_x;
	int m_velo_y;
public:
	Entity() = default;
	Entity(COORD pos, Shape* s);
	void render();
	void move(COORD pos);
	// virtual bool isImpact(const Entity& obj) const;
};