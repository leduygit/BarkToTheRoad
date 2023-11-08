#include "Screen.h"

void Screen::addButton(Button* b)
{
	m_buttons.push_back(b);
}

void Screen::setBackground(Shape* background)
{
	m_background = background;
}

std::vector<Button*> Screen::getButtons() const
{
	return std::vector<Button*>(m_buttons);
}

void Screen::render()
{
	m_background->render(0, 0);
	for (int i = 0; i < (int)m_buttons.size(); i++) {
		m_buttons[i]->render();
	}
}

void Screen::clickButton()
{
	for (Button* b : m_buttons) {
		if (b->isHovering()) {
			b->onClick();
			return;
		}
	}
}

Screen::~Screen() {
}