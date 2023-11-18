#include "GameScreen.h"

GameScreen::GameScreen(Gameplay*& gp) : m_gameplay{ gp }
{
	m_score_board = MyShape[SCORE];
	Button* input = new Button{ {500, 350}, MyShape[SCORE] };
	addButton(input);
	Button* open_dialog = new OpenDialogButton(MyShape[SCORE], m_render_dialog);
	open_dialog->setPos({ 500, 400 });
	addButton(open_dialog);

	m_menu = new Dialog{ MyShape[DOG_STAY_1], {100, 100} };
	Button* save = new SaveGameButton{ MyShape[DOG_STAY_2], m_gameplay};
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
	for (auto b : buttons) {
		b->render();
	}

	if (m_render_dialog) {
		m_menu->render();
		m_gameplay->setPause(true);
	}

	if (m_input_name) {
		COORD pos = getButtons()[0]->getPos();
		tmp.left = pos.X, tmp.top = 720 - pos.Y - 60;
		tmp.right = tmp.left + width;
		tmp.bottom = tmp.top + height;
		addText(new Text{ m_user_name, tmp });
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
	switch (key) {
	case 0x08:
	case 0x0A:
	case 0x1B:
	case 0x09:
		break;
	case 0x0D:
		if (m_user_name.size() == 0) break;
		m_input_name = false;
		m_gameplay->setPause(false);
		removeButton(0);
		break;
	default:
		if (m_user_name.size() >= 7) break;
		m_user_name += (TCHAR) key;
	}
}
