#pragma once
#include <windows.h>
#include "Global.h"
#include "ScreenId.h"
enum ButtonState {
	NORMAL, FOCUSED, CLICKED
};
class Button
{
public:
	Button() = default;
	Button(Shape* shape) : m_shape{ shape } {}
	Button(COORD pos, Shape* shape, ButtonState state = NORMAL) 
		: m_pos{ pos }, m_shape{ shape }, m_state{ state } {}

	void render();
	void setState(ButtonState s) {
		m_state = s;
	}
	void setPos(COORD pos);
	bool isInside(POINT p) const;
	bool isHovering() const;
	virtual void onClick() {
		OutputDebugStringA("Clicked");
		m_state = CLICKED;
	}
private:
	COORD m_pos{};
	ButtonState m_state{NORMAL};
	Shape* m_shape;
};

class ChangeScreenButton : public Button {
public:
	ChangeScreenButton(Shape* shape, ScreenId next_screen) : Button(shape), m_next_screen{ next_screen } {}
	void onClick();
private:
	ScreenId m_next_screen{};
};

class PauseButton : public Button {
public:
	void onClick();
};

class QuitButton : public Button {
public:
	QuitButton(Shape* shape) : Button(shape) {}
	void onClick() {
		Global::window_should_close = true;
	}
};