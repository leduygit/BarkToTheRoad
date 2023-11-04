#include "Button.h"

void Button::render()
{
	m_shape[m_state].render(m_pos.X, m_pos.Y);
}

void ChangeScreenButton::onClick()
{
}

void PauseButton::onClick()
{
}
