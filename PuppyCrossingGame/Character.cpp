#include "Character.h"
#include <cassert>

Character::~Character()
{
	//if (m_standing_shape) delete m_standing_shape;
	//if (m_initial_shape) delete m_initial_shape;
	//if (m_moving_shape) delete m_moving_shape;
}

void Character::Bark()
{
}

bool Character::isFinish()
{
	return false;
}

void Character::setPos(const COORD &pos)
{
	m_position = pos;
	m_new_position = pos;
}

bool Character::update()
{
	if (m_offset >= 90 && m_is_standing)
	{
		setPos({ m_position.X, m_position.Y - static_cast<SHORT>(90) });
		m_max_y -= 90;
		m_offset -= 90;
		return true;
	}
	return false;
	//m_position.Y = m_position.Y / 90 * 90;
}

void Character::updateOffset(int speed)
{
	m_offset += speed;
}

void Character::setMaxY(int max_y)
{
	m_max_y = max_y;
}

COORD Character::getPos()
{
	return m_position;
}

int Character::getMaxY() const
{
	return m_max_y;
}

void Character::setLeftDirection()
{
	m_initial_shape = DogMovingShapes[1];
	m_standing_shape = DogStayingShapes[1];
	m_moving_shape = DogMovingShapes[1];
}

void Character::setRightDirection()
{
	m_initial_shape = DogMovingShapes[0];
	m_standing_shape = DogStayingShapes[0];
	m_moving_shape = DogMovingShapes[0];
}

void Character::makeAnimation()
{
	int distanceX = m_new_position.X - m_old_position.X;
	int distanceY = m_new_position.Y - m_old_position.Y;

	int directionX = (distanceX > 0) ? 1 : -1;
	int directionY = (distanceY > 0) ? 1 : -1;

	bool conditionX = m_position.X >= m_old_position.X + (m_last_state + 1) * distanceX / m_total_state;
	bool conditionY = m_position.Y >= m_old_position.Y + (m_last_state + 1) * distanceY / m_total_state;

	if (directionX == -1) conditionX = m_position.X <= m_old_position.X + (m_last_state + 1) * distanceX / m_total_state;
	if (directionY == -1) conditionY = m_position.Y <= m_old_position.Y + (m_last_state + 1) * distanceY / m_total_state;

	if (conditionX && conditionY)
	{
		if (m_last_state + 1 < m_total_state) {
			m_shape = &m_moving_shape[m_last_state];
			m_last_state++;
		}
		else if (m_last_state + 1 == m_total_state) {
			m_last_state = 0;
			m_shape = m_initial_shape;
		}
	}
}

bool Character::isStanding() const {
	return m_is_standing;
}

void Character::move(const COORD &pos) {
	m_is_standing = false;
	m_new_position = { static_cast<short>(pos.X / 90 * 90), pos.Y / 90 * 90 };// 
	
	m_delta = { static_cast<short>((m_new_position.X - m_position.X) / 9), static_cast<short>((m_new_position.Y - m_position.Y) / 9) };
	m_old_position = m_position;
}

void Character::moveInRaft(const COORD &pos)
{
	m_is_standing = true;
	m_new_position = pos;
	m_delta = { static_cast<short>((m_new_position.X - m_position.X) / 30), static_cast<short>((m_new_position.Y - m_position.Y) / 30) };
}

void Character::render() {
	if (m_position.X == m_new_position.X && m_position.Y == m_new_position.Y) {
		m_is_standing = true;
		m_last_state = 0;
	}
	else {
		m_position.X += (abs(m_new_position.X - m_position.X) > abs(m_delta.X)) ? m_delta.X : m_new_position.X - m_position.X;
		m_position.Y += (abs(m_new_position.Y - m_position.Y) > abs(m_delta.Y)) ? m_delta.Y : m_new_position.Y - m_position.Y;
	}

	if (m_is_standing) {
		int r = rand() % 2;
		assert(r >= 0 && r < 2);
		m_shape = &m_standing_shape[r];
	}

	if (m_is_standing == false) makeAnimation();

	Entity::render(m_offset);
}

void Character::setShape(Shape* shape)
{
	m_standing_shape = shape;
}

std::istream& operator>>(std::istream& in, Character& c)
{
	int x, y, total_state, maxY, offset, skinIndex;
	in >> x >> y >> total_state;
	COORD position = { x, y };
	in >> maxY;
	in >> skinIndex;
	in >> offset;

	Shape* moving = DogMovingShapes[skinIndex];
	Shape* staying = DogStayingShapes[skinIndex];
	c = Character(position, staying, moving, total_state);
	c.m_max_y = maxY;
	c.m_offset = offset;
	c.m_skinIndex = skinIndex;
	return in;
}

std::ostream& operator<<(std::ostream& out, const Character& c)
{
	out << c.m_position.X << " " << c.m_position.Y << " " << c.m_total_state << " " ;
	out << c.m_max_y << " ";
	out << c.m_skinIndex << " ";
	out << c.m_offset << " ";
	return out;
}
