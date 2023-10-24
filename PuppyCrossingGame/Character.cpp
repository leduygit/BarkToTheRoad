#include "Character.h"

void Character::Bark()
{
}

bool Character::isFinish()
{
	return false;
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
	Entity::move(pos);
}

void Character::render() {
	if (m_position.X == m_new_position.X && m_position.Y == m_new_position.Y) {
		m_is_standing = true;
	}
	Entity::render();
}