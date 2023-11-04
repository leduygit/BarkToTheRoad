#include "Button.h"
#include<string>

void Button::render()
{
	if (m_state != CLICKED) {
		if (isHovering()) setState(FOCUSED);
		else setState(NORMAL);
	}
	else {
		std::string a = "State is: " + std::to_string(m_state) + '\n';
		OutputDebugStringA(a.c_str());
	}

	m_shape[m_state].render(m_pos.X, m_pos.Y);
}

bool Button::isInside(POINT p) const
{
	int height = 0, width = 0;
	m_shape->getSize(height, width);
	p.y = 720 - p.y;
	return (p.x >= m_pos.X && p.x <= m_pos.X + width 
		&& p.y >= m_pos.Y && p.y <= m_pos.Y + height);
}

bool Button::isHovering() const
{
	POINT mouse_pos;
	if (GetCursorPos(&mouse_pos) == 0) return false;
	ScreenToClient(Global::window, &mouse_pos);
	return isInside(mouse_pos);
}

void ChangeScreenButton::onClick()
{
}

void PauseButton::onClick()
{
}
