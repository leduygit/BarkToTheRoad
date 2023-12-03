#include "CreditScreen.h"

CreditScreen::CreditScreen() : m_board(MyShape[CREDIT_WINDOW])
{
	setBackground(MyShape[BACKGROUND_EMPTY]);
	Shape* homeButtonState = new Shape[2]{ *MyShape[HOME], *MyShape[HOME_HOVER] };
	Button* homeButton = new ChangeScreenButton{ homeButtonState, MENU_SCREEN };
	homeButton->setPos({ 615, 130 });
	m_buttons.push_back(homeButton);
}

void CreditScreen::render()
{
	m_background->render(0, 0);
	m_board->render(250, 75);

	for (auto button : getButtons()) {
		button->render();
	}
}
