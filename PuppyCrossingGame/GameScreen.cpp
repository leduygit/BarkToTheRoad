#include "GameScreen.h"

GameScreen::GameScreen(Gameplay* gp) : m_gameplay{ gp }
{
	m_score_board = MyShape[SCORE];
	Button* input = new Button{ {500, 350}, MyShape[SCORE] };
	addButton(input);
	Shape* pauseButtonState = new Shape[2]{ *MyShape[PAUSE], *MyShape[PAUSE] };
	Button* open_dialog = new OpenDialogButton(pauseButtonState, m_render_dialog);
	open_dialog->setPos({ 500, 400 });
	addButton(open_dialog);

	m_menu = new Dialog{ MyShape[DOG_STAY_1], {100, 100} };
	Shape* saveGameButtonState = new Shape[2]{ *MyShape[SAVE_GAME_BUTTON], *MyShape[SAVE_GAME_BUTTON_HOVER] };
	Button* save = new SaveGameButton{ saveGameButtonState, m_gameplay, m_render_dialog};
	save->setPos({ 150, 100 });
	m_menu->addButton(save);

	Shape* state = new Shape[2] {*MyShape[RANK_BUTTON], *MyShape[RANK_BUTTON]};
	Button* close_dialog = new CloseDialogButton{ state, m_render_dialog, m_gameplay };
	close_dialog->setPos({ 150, 300 });
	m_menu->addButton(close_dialog);
}

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

	auto buttons = getButtons();
	for (int i = 0; i < buttons.size(); i++) {
		if (i == 0) {
			if (!m_gameplay->getIsNewGame()) continue;
		}
		buttons[i]->render();
	}

	if (m_render_dialog) {
		m_menu->render();
		m_gameplay->setPause(true);
	}

	if (m_gameplay->getIsNewGame()) {
		COORD pos = getButtons()[0]->getPos();
		tmp.left = pos.X, tmp.top = 720 - pos.Y - 60;
		tmp.right = tmp.left + width;
		tmp.bottom = tmp.top + height;
		addText(new Text{ m_gameplay->getUserName(), tmp});
	}
}

void GameScreen::clean()
{
	Screen::clearTexts();
}

void GameScreen::clickButton()
{
	Screen::clickButton();
	auto buttons = m_menu->getButtons();
	for (auto b : buttons) {
		if (b->isHovering()) {
			b->onClick();
			break;
		}
	}
}

void GameScreen::handleKeyPressed(WPARAM key)
{
	std::string &user_name = m_gameplay->getUserName();
	switch (key) {
	case 0x08:
	case 0x0A:
	case 0x1B:
	case 0x09:
		break;
	case 0x0D:
		if (user_name.size() == 0) break;
		m_gameplay->setPause(false);
		m_gameplay->setIsNewGame(false);
		break;
	default:
		if (user_name.size() >= 7) break;
		user_name += (TCHAR) key;
	}
}
