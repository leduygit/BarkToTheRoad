#pragma once
#include "Screen.h"
#include "Gameplay.h"
#include "Dialog.h"
class GameScreen: public Screen
{
public:
	GameScreen() = default;
	GameScreen(Gameplay* gp);
	void render() override;
	void renderText() const override;
	void clean() override;
	void clickButton() override;
	void initDialog();
	void updateDialog();
	void handleKeyPressed(WPARAM key) override;
private:
	Gameplay* m_gameplay{ nullptr };
	Dialog* m_menu{nullptr};
	HDC *m_hdc{nullptr};
	Shape* m_score_board{ nullptr };
	RECT m_score_pos{};
	bool m_input_name{ true };
	bool m_render_dialog{ false };
	bool m_init_dialog{ true };
	bool m_finish{ false };
};

