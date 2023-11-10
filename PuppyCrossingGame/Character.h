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
	Character(const COORD &pos, Shape* standing, Shape* moving, int total = 1) : 
		Entity(pos, standing), m_total_state{ total },  m_standing_shape{ standing },
		m_initial_shape{ moving }, m_moving_shape{ moving } {}
	~Character();
	void Bark();
	bool isFinish(); // isDead checking
	bool isStanding() const;
	void render(int offset);
	void move(const COORD &pos);
	void moveInRaft(const COORD &pos);
	void setPos(const COORD &pos);
	void update(int& offset);
	COORD getPos();
};

