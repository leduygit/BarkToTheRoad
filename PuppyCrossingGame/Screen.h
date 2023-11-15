#pragma once
#include <vector>
#include "Button.h"
#include "LoadShape.h"
#include "Text.h"
class Screen
{
public:
	Screen() = default;
	Screen(Shape* background) : m_background{ background } {}
	~Screen();
	void addButton(Button* b);
	void setBackground(Shape* background);
	void addText(Text* s) {
		m_texts.push_back(s);
	}
	void clearTexts() {
		for (auto text : m_texts) {
			delete text;
		}
		m_texts.clear();
	}

	std::vector<Button*> getButtons() const;
	std::vector<Text*> getTexts() const;
	virtual void render();
	virtual void clean();
	void clearText();
	void renderText() const;
	void clickButton();
private:
	Shape* m_background;
	std::vector<Button*> m_buttons;
	std::vector<Text*> m_texts{};
};

