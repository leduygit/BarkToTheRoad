#include "Dialog.h"

void Dialog::render()
{
	m_background->render(m_pos.X, m_pos.Y);
	for (auto b : m_buttons) {
		b->render();
	}
}

void Dialog::addButton(Button* b)
{
	m_buttons.push_back(b);
}

void Dialog::clearButtons()
{
	for (auto b : m_buttons) {
		delete b;
	}
	m_buttons.clear();
}
