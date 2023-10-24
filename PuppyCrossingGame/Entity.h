#pragma once
#include "windows.h"
#include "Shape.h"
class Entity
{
private:
	//int m_width;
	//int m_height;
	int m_velo_x;
	int m_velo_y;

protected:
	COORD m_position;
	COORD m_new_position;
	Shape* m_shape;
public:
	Entity() = default;
	Entity(COORD pos, Shape* s);
	void render();
	void move(COORD pos);
	// virtual bool isImpact(const Entity& obj) const;
	bool isCollison(const Entity& e);
};