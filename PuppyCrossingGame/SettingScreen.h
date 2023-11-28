#pragma once
#include "Screen.h"
class SettingScreen : public Screen
{
public:
	SettingScreen();
	void render();
private:
	Shape* m_board{};
	Button* m_music{};
	Button* m_music_muted{};
	Button* m_sound{};
	Button* m_sound_muted{};
};

