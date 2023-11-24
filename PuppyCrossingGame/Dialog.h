#pragma once
#include <vector>
#include "Button.h"
class Dialog
{
public:
	Dialog() = default;
	Dialog(Shape* bg, COORD pos) : m_background{ bg }, m_pos{ pos } {}
	void render();
	void addButton(Button* b);
	void clearButtons();
	std::vector<Button*> getButtons() const {
		return m_buttons;
	}
private:
	Shape* m_background{ nullptr };
	COORD m_pos{};
	std::vector<Button*> m_buttons{};
};

