#pragma once
#include "Screen.h"
#include "Gameplay.h"
class GameScreen: public Screen
{
public:
	GameScreen() = default;
	GameScreen(Gameplay* gp, Shape* score_board) : m_gameplay{ gp }, m_score_board{ score_board } {
		m_score_pos.left = 100;
		m_score_pos.top = 350;
		m_score_pos.right = 300;
		m_score_pos.bottom = 200;
	}
	void render() override;
	void clean() override;
private:
	Gameplay* m_gameplay{ nullptr };
	HDC *m_hdc{nullptr};
	Shape* m_score_board{ nullptr };
	RECT m_score_pos{};
};

