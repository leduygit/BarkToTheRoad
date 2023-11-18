#pragma once
#include "Screen.h"
#include "Gameplay.h"
#include "Dialog.h"
class GameScreen: public Screen
{
public:
	GameScreen() = default;
	GameScreen(Gameplay*& gp);
	void render() override;
	void clean() override;
	void clickButton() override;
	void handleKeyPressed(WPARAM key) override;
private:
	Gameplay* m_gameplay{ nullptr };
	Dialog* m_menu{nullptr};
	HDC *m_hdc{nullptr};
	Shape* m_score_board{ nullptr };
	RECT m_score_pos{};
	std::string m_user_name{ "" };
	bool m_input_name{ true };
	bool m_render_dialog{ false };
};

