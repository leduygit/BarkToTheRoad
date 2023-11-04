#pragma once
#include <windows.h>
#include "Global.h"
enum ButtonState {
	NORMAL, FOCUSED, CLICKED
};
class Button
{
public:
	Button() = default;
	Button(COORD pos, Shape* shape, ButtonState state = NORMAL) 
		: m_pos{ pos }, m_shape{ shape }, m_state{ state } {}

	void render();
	void setState(ButtonState s) {
		m_state = s;
	}
	bool isInside(POINT p) const;
	bool isHovering() const;
	virtual void onClick() {
		OutputDebugStringA("Clicked");
		m_state = CLICKED;
	}
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