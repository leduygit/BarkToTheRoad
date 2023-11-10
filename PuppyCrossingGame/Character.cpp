#include "Character.h"
#include <cassert>

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

void Character::update(int& offset)
{
	if (offset == 0)
	{
		setPos({ m_position.X, m_position.Y - 90 });
		m_position.Y = m_position.Y / 90 * 90;
	}
}

COORD Character::getPos()
{
	return m_position;
}

bool Character::isStanding() const {
	return m_is_standing;
}

void Character::move(const COORD &pos) {
	m_is_standing = false;
	m_new_position = { static_cast<short>(pos.X ), pos.Y  };// / 90 * 90
	
	m_delta = { static_cast<short>((m_new_position.X - m_position.X) / m_total_state), static_cast<short>((m_new_position.Y - m_position.Y) / m_total_state) };
}

void Character::moveInRaft(const COORD &pos)
{
	m_is_standing = true;
	m_new_position = pos;
	m_delta = { static_cast<short>((m_new_position.X - m_position.X) / 30), static_cast<short>((m_new_position.Y - m_position.Y) / 30) };
}

void Character::render(int offset) {
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

	if (m_last_state + 1 < m_total_state && !m_is_standing) {
		m_shape = &m_moving_shape[m_last_state];
		m_last_state++;
	}
	else if (m_last_state + 1 == m_total_state) {
		m_last_state = 0;
		m_shape = m_initial_shape;
	}

	Entity::render(offset);
}