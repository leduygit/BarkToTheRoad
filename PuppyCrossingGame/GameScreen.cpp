#include "GameScreen.h"

void GameScreen::render() {
	m_gameplay->gameLogic();

	char score[3];
	_itoa_s(m_gameplay->getScore(), score, 10);

	RECT tmp;
	int height, width;
	m_score_board->getSize(width, height);
	tmp.left = 500;
	tmp.top = 20;
	tmp.right = tmp.left + width;
	tmp.bottom = tmp.top + height;
	m_score_board->render(500, 635);
	addText(new Text{ score, tmp });
}