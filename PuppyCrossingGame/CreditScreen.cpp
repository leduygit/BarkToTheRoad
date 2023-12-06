#include "CreditScreen.h"

CreditScreen::CreditScreen(int id)
{
	setBackground(MyShape[BACKGROUND_EMPTY]);
	Shape* boardState = new Shape[3]{*MyShape[CREDIT_WINDOW], *MyShape[INSTRUCTION_WINDOW_1], *MyShape[INSTRUCTION_WINDOW_2]};
	Shape* homeButtonState = new Shape[2]{ *MyShape[HOME], *MyShape[HOME_HOVER] };

	Button* homeButton = new ChangeScreenButton{ homeButtonState, MENU_SCREEN };
	homeButton->setPos({ 621, 122 });
	m_buttons.push_back(homeButton);

	Shape* preButtonState = new Shape[2]{ *MyShape[PRE_BUTTON], *MyShape[PRE_BUTTON_HOVER] };
	Shape* nextButtonState = new Shape[2]{ *MyShape[NEXT_BUTTON], *MyShape[NEXT_BUTTON_HOVER] };
	
	if (id == 0) {
		m_board = (MyShape[CREDIT_WINDOW]);
		Button* nextButton = new ChangeScreenButton{ nextButtonState, CREDIT_SCREEN_1 };
		nextButton->setPos({ 961, 132 });
		m_buttons.push_back(nextButton);
	}
	else if (id == 1) {
		m_board = (MyShape[INSTRUCTION_WINDOW_1]);
		Button* preButton = new ChangeScreenButton{ preButtonState, CREDIT_SCREEN_0 };
		preButton->setPos({ 311, 132 });
		m_buttons.push_back(preButton);
		Button* nextButton = new ChangeScreenButton{ nextButtonState, CREDIT_SCREEN_2 };
		nextButton->setPos({ 961, 132 });
		m_buttons.push_back(nextButton);
	}
	else if (id == 2) {
		m_board = (MyShape[INSTRUCTION_WINDOW_2]);
		Button* preButton = new ChangeScreenButton{ preButtonState, CREDIT_SCREEN_1 };
		preButton->setPos({ 311, 132 });
		m_buttons.push_back(preButton);
	}
}

void CreditScreen::render()
{
	m_background->render(0, 0);
	m_board->render(250, 75);

	for (auto button : getButtons()) {
		button->render();
	}
}
