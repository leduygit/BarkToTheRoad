#include "GameScreen.h"

GameScreen::GameScreen(Gameplay* gp) : m_gameplay{ gp }
{
	m_score_board = MyShape[SCORE];
	Shape* inputButtonState = new Shape[2]{ *MyShape[TEXTBOX], *MyShape[TEXTBOX] };
	Button* input = new Button{ {465, 353}, inputButtonState };
	addButton(input);
	Shape* pauseButtonState = new Shape[2]{ *MyShape[PAUSE], *MyShape[PAUSE] };
	Button* open_dialog = new OpenDialogButton(pauseButtonState, m_render_dialog);
	open_dialog->setPos({ 1200, 650 });
	addButton(open_dialog);

	initDialog();
}

void GameScreen::render() {
	m_gameplay->gameLogic();
	if (m_gameplay->getEnded() && m_gameplay->vehicleArrived()) {
		updateDialog();
		if (!m_finish) {
			Sleep(500);
			m_finish = true;
		}
		
		m_render_dialog = true;
		m_init_dialog = false;
	}
	else if (!m_init_dialog) {
		m_finish = false;
		initDialog();
	}

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
			else {
				m_gameplay->setPause(true);
			}
		}
		buttons[i]->render();
	}

	if (m_render_dialog) {
		m_menu->render();
		m_gameplay->setPause(true);
	}

	if (m_gameplay->getIsNewGame()) {
		initDialog();
		COORD pos = buttons[0]->getPos();
		buttons[0]->getSize(width, height);
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
	if (m_render_dialog) {
		auto buttons = m_menu->getButtons();
		for (auto b : buttons) {
			if (b->isHovering()) {
				b->onClick();
				break;
			}
		}
	}
}

void GameScreen::initDialog()
{
	m_init_dialog = true;
	m_menu = new Dialog{ MyShape[PAUSE_WINDOW], {400, 200} };

	Shape* resumeButtonState = new Shape[2]{ *MyShape[RESUME_BUTTON], *MyShape[RESUME_BUTTON_HOVER] };
	Button* resumeButton = new CloseDialogButton{ resumeButtonState, m_render_dialog, m_gameplay };
	resumeButton->setPos({ 542, 382 });
	m_menu->addButton(resumeButton);

	Shape* saveGameButtonState = new Shape[2]{ *MyShape[SAVE_GAME_BUTTON], *MyShape[SAVE_GAME_BUTTON_HOVER] };
	Button* save = new ChangeScreenButton{ saveGameButtonState, SAVE_SCREEN };
	save->setPos({ 542, 312 });
	m_menu->addButton(save);

	Shape* returnHomeButtonState = new Shape[2]{ *MyShape[HOME], *MyShape[HOME_HOVER] };
	Button* returnHome = new ChangeScreenButton{ returnHomeButtonState, MENU_SCREEN };
	returnHome->setShowDialog(m_render_dialog);
	returnHome->setPos({ 620, 231 });
	m_menu->addButton(returnHome);

	Shape* state = new Shape[2]{ *MyShape[CLOSE_DIALOG], *MyShape[CLOSE_DIALOG] };
	Button* close_dialog = new CloseDialogButton{ state, m_render_dialog, m_gameplay };
	close_dialog->setPos({ 830, 490 });
	m_menu->addButton(close_dialog);
}

void GameScreen::updateDialog()
{
	m_menu = new Dialog{ MyShape[GAME_OVER], {400, 200 } };

	Shape* returnHomeButtonState = new Shape[2]{ *MyShape[HOME], *MyShape[HOME_HOVER] };
	Button* returnHome = new ChangeScreenButton{ returnHomeButtonState, MENU_SCREEN };
	returnHome->setShowDialog(m_render_dialog);
	returnHome->setPos({ 907, 240 });
	m_menu->addButton(returnHome);

	Shape* rankButtonState = new Shape[2]{ *MyShape[TROPHY_SMALL], *MyShape[TROPHY_SMALL] };
	Button* rankButton = new ChangeScreenButton{ rankButtonState, RANK_SCREEN };
	rankButton->setShowDialog(m_render_dialog);
	rankButton->setPos({ 828, 240 });
	m_menu->addButton(rankButton);
}

void GameScreen::handleKeyPressed(WPARAM key)
{
	if (m_gameplay->getEnded()) return;
	std::string &user_name = m_gameplay->getUserName();
	switch (key) {
	case 0x08:
		if (!user_name.empty()) {
			user_name.pop_back();
		}
		break;
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
