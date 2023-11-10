#include "MenuScreen.h"
MenuScreen::MenuScreen() {
	setBackground(MyShape[BACKGROUND]);
	// add multiple button states!!!
	Shape* newGameButtonState = new Shape[3]{ *MyShape[NEW_GAME_BUTTON], *MyShape[NEW_GAME_BUTTON_HOVER] };
	Button* newGameButton = new ChangeScreenButton(newGameButtonState, GAME_SCREEN);
	Shape* loadGameButtonState = new Shape[3]{ *MyShape[LOAD_GAME_BUTTON], *MyShape[LOAD_GAME_BUTTON_HOVER] };
	Button* loadGameButton = new ChangeScreenButton(loadGameButtonState, LOAD_SCREEN);
	Shape* rankButtonState = new Shape[3]{ *MyShape[RANK_BUTTON], *MyShape[RANK_BUTTON_HOVER] };
	Button* rankButton = new ChangeScreenButton(rankButtonState, RANK_SCREEN);
	addButton(newGameButton);
	addButton(loadGameButton);
	addButton(rankButton);

	std::vector<Button*> buttons = getButtons();
	for (int i = (int) buttons.size() - 1; i >= 0; i--) {
		buttons[i]->setPos({ 500, static_cast<short>(100 * (buttons.size() - i)) });
	}
}