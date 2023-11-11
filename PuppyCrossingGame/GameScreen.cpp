#include "GameScreen.h"

void GameScreen::render() {
	m_gameplay->gameLogic();

	char score[3];
	_itoa_s(m_gameplay->getScore(), score, 10);

	// https://stackoverflow.com/questions/19715144/how-to-convert-char-to-lpcwstr
	wchar_t wtext[5];
	MultiByteToWideChar(CP_ACP, 0, score, -1, wtext, 5);
	LPWSTR ptr = wtext;
	//OutputDebugString(ptr);

	//m_score_board->render(100, 300);
	DrawTextW(*m_hdc, ptr, -1, &m_score_pos, DT_NOCLIP);
}