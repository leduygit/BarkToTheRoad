#include "Screen.h"

void Screen::addButton(Button* b)
{
	m_buttons.push_back(b);
}

void Screen::removeButton(int i)
{
	m_buttons.erase(m_buttons.begin() + i);
}

void Screen::setBackground(Shape* background)
{
	m_background = background;
}

std::vector<Button*> Screen::getButtons() const
{
	return std::vector<Button*>(m_buttons);
}

std::vector<Text*> Screen::getTexts() const
{
	return m_texts;
}

void Screen::render()
{
	updateContent();
	m_background->render(0, 0);
	for (int i = 0; i < (int)m_buttons.size(); i++) {
		m_buttons[i]->render();
	}
}

void Screen::clean()
{
	return;
}

void Screen::clearText()
{
	for (auto text : m_texts) delete text;
	m_texts.clear();
}

void Screen::renderText() const
{
	for (auto text : m_texts) {
		text->render();
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