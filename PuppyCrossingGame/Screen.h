#pragma once
#include <vector>
#include "Button.h"
#include "LoadShape.h"
class Screen
{
public:
	Screen() = default;
	Screen(Shape* background) : m_background{ background } {}
	~Screen();
	void addButton(Button* b);
	void setBackground(Shape* background);
	std::vector<Button*> getButtons() const;
	void render();
	void clickButton();
private:
	Shape* m_background;
	std::vector<Button*> m_buttons;
	int m_selected_button = -1;
};

