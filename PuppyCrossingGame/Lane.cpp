#include "Lane.h"

void Lane::render()
{
	for (int i = 0; i < 10; i++) {
		m_shape.render(m_position.X + 90 * i, m_position.Y);
	}
}
