#include "MenuScreen.h"
MenuScreen::MenuScreen(Gameplay* gp) {
	setBackground(MyShape[BACKGROUND]);
	// add multiple button states!!!
	Shape* newGameButtonState = new Shape[2]{ *MyShape[NEW_GAME_BUTTON], *MyShape[NEW_GAME_BUTTON_HOVER] };
	Button* newGameButton = new NewGameButton(newGameButtonState, gp);
	newGameButton->setPos({ 500, 300 });

	Shape* loadGameButtonState = new Shape[2]{ *MyShape[LOAD_GAME_BUTTON], *MyShape[LOAD_GAME_BUTTON_HOVER] };
	Button* loadGameButton = new ChangeScreenButton(loadGameButtonState, LOAD_SCREEN);
	loadGameButton->setPos({ 500, 200 });

	Shape* rankButtonState = new Shape[2]{ *MyShape[RANK_BUTTON], *MyShape[RANK_BUTTON_HOVER] };
	Button* rankButton = new ChangeScreenButton(rankButtonState, RANK_SCREEN);
	rankButton->setPos({ 830, 138 });

	Shape* quitButtonState = new Shape[2]{ *MyShape[QUIT_BUTTON], *MyShape[QUIT_BUTTON_HOVER] };
	Button* quitButton = new QuitButton(quitButtonState);
	quitButton->setPos({ 1000, 10 });

	Shape* settingButtonState = new Shape[2]{ *MyShape[SETTING_BUTTON], *MyShape[SETTING_BUTTON] };
	Button* settingButton = new ChangeScreenButton(settingButtonState, SETTING_SCREEN);
	settingButton->setPos({ 1150, 650 });

	addButton(newGameButton);
	addButton(loadGameButton);
	addButton(rankButton);
	addButton(quitButton);
	addButton(settingButton);
}