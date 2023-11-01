#pragma once
#include "Entity.h"

class Character : public Entity
{
private:
	bool isDead{};
	bool m_is_standing{ true };
	int m_total_state{};
	int m_last_state{};
	Shape* m_standing_shape;
	Shape* m_initial_shape;
	Shape* m_moving_shape;
	COORD m_delta;
public:
	Character() = default;
	Character(COORD pos, Shape* standing, Shape* moving, int total = 1) : 
		Entity(pos, standing), m_total_state{ total },  m_standing_shape{ standing },
		m_initial_shape{ moving }, m_moving_shape{ moving } {}
	void Bark();
	bool isFinish(); // isDead checking
	bool isStanding() const;
	void render();
	void move(COORD pos);
	void moveInRaft(COORD pos);
	void setPos(COORD pos);
	COORD getPos();
};

