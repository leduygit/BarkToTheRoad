#pragma once
#include "windows.h"
#include "Shape.h"
class Entity
{
private:
	COORD m_new_position;
	//int m_width;
	//int m_height;
	int m_velo_x;
	int m_velo_y;

protected:
	COORD m_position;
	Shape* m_shape;
public:
	Entity() = default;
	Entity(COORD pos, Shape* s);
	void render();
	void move(COORD pos);
	// virtual bool isImpact(const Entity& obj) const;
};