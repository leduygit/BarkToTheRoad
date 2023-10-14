#include "Entity.h"

void Entity::render() {
	m_shape.render(m_position.X, m_position.Y);
}