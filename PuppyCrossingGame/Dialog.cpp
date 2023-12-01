#include "Dialog.h"

void Dialog::render()
{
	m_background->render(m_pos.X, m_pos.Y);
	for (auto b : m_buttons) {
		b->render();
	}
}

void Dialog::renderTexts()
{
	for (auto t : m_texts) {
		t->render();
	}
}

void Dialog::addButton(Button* b)
{
	m_buttons.push_back(b);
}

void Dialog::addText(Text* t)
{
	m_texts.push_back(t);
}

void Dialog::clearButtons()
{
	for (auto b : m_buttons) {
		delete b;
	}
	m_buttons.clear();
}
