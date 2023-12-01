#pragma once
#include "Entity.h"

class Character : public Entity
{
private:
	bool isDead{};
	bool m_is_standing{ true };
	int m_total_state{};
	int m_last_state{};
	int m_max_y{ 0 };
	Shape* m_standing_shape;
	Shape* m_initial_shape;
	Shape* m_moving_shape;
	COORD m_delta = { 0, 0 };
	int m_skinIndex{ 0 };
	int m_offset{ 0 };
public:
	Character() = default;
	Character(const COORD& pos, Shape* standing, Shape* moving, int total = 1) :
		Entity(pos, standing), m_total_state{ total }, m_standing_shape{ standing },
		m_initial_shape{ moving }, m_moving_shape{ moving }
	{
		m_new_position = m_position;
		m_delta = { 0, 0 };
	}
	~Character();
	void Bark();
	bool isFinish(); // isDead checking
	bool isStanding() const;
	void render();
	void setShape(Shape* shape);
	void move(const COORD &pos);
	void moveInRaft(const COORD &pos);
	void setPos(const COORD &pos);
	void setMaxY(int max_y);
	bool update();
	void updateOffset(int speed);
	COORD getPos();
	int getMaxY() const;
	void setLeftDirection();
	void setRightDirection();
	friend std::istream& operator>>(std::istream& in, Character &c);
	friend std::ostream& operator<<(std::ostream& out, const Character &c);
};

