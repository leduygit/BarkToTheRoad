#pragma once
#include <vector>
#include "Button.h"
#include "Text.h"
class Dialog
{
public:
	Dialog() = default;
	Dialog(Shape* bg, COORD pos) : m_background{ bg }, m_pos{ pos } {}
	void render();
	void renderTexts();
	void addButton(Button* b);
	void addText(Text* t);
	void clearButtons();
	std::vector<Button*> getButtons() const {
		return m_buttons;
	}
private:
	Shape* m_background{ nullptr };
	COORD m_pos{};
	std::vector<Button*> m_buttons{};
	std::vector<Text*> m_texts{};
};

