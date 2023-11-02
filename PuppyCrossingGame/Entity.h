#pragma once
#include "windows.h"
#include "Global.h"
#include "LoadShape.h"
class Entity
{
private:
	//int m_width;
	//int m_height;
	int m_velo_x;
	int m_velo_y;
	int m_rate{ 30 };

protected:
	COORD m_position;
	COORD m_new_position;
	Shape* m_shape;
public:
	Entity() = default;
	Entity(const COORD &pos, Shape* s);
	void render();
	void move(const COORD &pos);
	void setRate(int rate) {
		m_rate = rate;
	}
	// virtual bool isImpact(const Entity& obj) const;
	virtual bool isCollison(const Entity& e);
};
