#pragma once
#include <vector>
#include "Button.h"
class Screen
{
public:
	Screen() = default;
	Screen(Shape* background) : m_background{ background } {}
	void addButton(Button* b);
	std::vector<Button*> getButtons() const;
	void render();
	void clickButton();
private:
	Shape* m_background;
	std::vector<Button*> m_buttons;
	int m_selected_button = -1;
};

