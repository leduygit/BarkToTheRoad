#include "Entity.h"

Entity::Entity(COORD pos, Shape* s)
{
	m_position = pos;
	m_shape = s;
}

void Entity::render() {
	/*if (m_position.X != m_new_position.X) {
		m_position.X += m_velo_x;
	}
	else {
		m_velo_x = 0;
	}
	if (m_position.Y != m_new_position.Y) {
		m_position.Y += m_velo_y;
	}
	else {
		m_velo_y = 0;
	}*/

	m_shape->render(m_position.X, m_position.Y);
}

void Entity::move(COORD pos) {
	m_new_position = pos;
	m_velo_x = (pos.X - m_position.X) / 60;
	m_velo_y = (pos.Y - m_position.Y) / 60;
}