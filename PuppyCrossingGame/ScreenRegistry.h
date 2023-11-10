#pragma once
#include "Screen.h"
#include "MenuScreen.h"
class ScreenRegistry
{
public:
	Screen* getCurrentScreen() const {
		return m_screens[Global::current_screen];
	}

	void initialize() {
		m_screens.push_back(new MenuScreen{});
	}

	void addScreen(Screen* s) {
		m_screens.push_back(s);
	}
private:
	std::vector<Screen*> m_screens;
};

