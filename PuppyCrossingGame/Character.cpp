#include "Character.h"
#include <cassert>

void Character::Bark()
{
}

bool Character::isFinish()
{
	return false;
}

void Character::setPos(COORD pos)
{
	m_position = pos;
	m_new_position = pos;
}

COORD Character::getPos()
{
	return m_position;
}

bool Character::isStanding() const {
	return m_is_standing;
}

void Character::move(COORD pos) {
	m_is_standing = false;
	m_new_position = pos;
	m_delta = { static_cast<short>((m_new_position.X - m_position.X) / m_total_state), static_cast<short>((m_new_position.Y - m_position.Y) / m_total_state) };
}

void Character::render() {
	if (m_position.X == m_new_position.X && m_position.Y == m_new_position.Y) {
		m_is_standing = true;
		m_last_state = 0;
	}
	else {
		m_position.X += m_delta.X;
		m_position.Y += m_delta.Y;
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

	Entity::render();
}