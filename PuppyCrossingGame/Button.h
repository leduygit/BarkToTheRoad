#pragma once
#include <windows.h>
#include "Global.h"
#include "ScreenId.h"
#include "Gameplay.h"
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
	COORD getPos() const;
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

class SaveGameButton : public Button {
public:
	SaveGameButton(Shape* shape, Gameplay* gp) : Button(shape), m_gp{ gp } {}
	void onClick() {
		m_gp->saveGame();
		Global::current_screen = MENU_SCREEN;
	}
	
private:
	Gameplay* m_gp{ nullptr };
};

class OpenDialogButton : public Button {
public:
	OpenDialogButton(Shape* shape, bool& show) : Button(shape), m_show{ &show } {}
	void onClick() {
		*m_show = true;
	}
private:
	bool *m_show;
};

class CloseDialogButton : public Button {
public:
	CloseDialogButton(Shape* shape, bool& show) : Button(shape), m_show{ &show } {}
	void onClick() {
		*m_show = false;
		std::string a = "Clicked\n";
		OutputDebugStringA(a.c_str());
	}
private:
	bool* m_show;
};