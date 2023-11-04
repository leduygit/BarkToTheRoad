#pragma once
#include <windows.h>
#include "Global.h"
enum ButtonState {
	NORMAL, FOCUSED
};
class Button
{
public:
	Button() = default;
	Button(COORD pos, Shape* shape, ButtonState state = NORMAL) 
		: m_pos{ pos }, m_shape{ shape }, m_state{ state } {}

	void render();
	void changeState() {
		if (m_state == NORMAL) m_state = FOCUSED;
		else m_state = NORMAL;
	}
	virtual void onClick() {}
private:
	COORD m_pos{};
	ButtonState m_state{};
	Shape* m_shape;
};

class ChangeScreenButton : public Button {
public:
	void onClick();
};

class PauseButton : public Button {
public:
	void onClick();
};