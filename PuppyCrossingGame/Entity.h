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
	void render() const;
	void move(COORD pos);
	virtual bool isImpact(const Entity& obj) const;
};