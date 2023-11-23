#include "MenuScreen.h"
MenuScreen::MenuScreen(Gameplay* gp) {
	setBackground(MyShape[BACKGROUND]);
	// add multiple button states!!!
	Shape* newGameButtonState = new Shape[2]{ *MyShape[NEW_GAME_BUTTON], *MyShape[NEW_GAME_BUTTON_HOVER] };
	Button* newGameButton = new NewGameButton(newGameButtonState, gp);
	newGameButton->setPos({ 500, 300 });

	Shape* loadGameButtonState = new Shape[2]{ *MyShape[LOAD_GAME_BUTTON], *MyShape[LOAD_GAME_BUTTON_HOVER] };
	Button* loadGameButton = new LoadGameButton(loadGameButtonState, gp);
	loadGameButton->setPos({ 500, 200 });

	Shape* rankButtonState = new Shape[2]{ *MyShape[RANK_BUTTON], *MyShape[RANK_BUTTON_HOVER] };
	Button* rankButton = new ChangeScreenButton(rankButtonState, RANK_SCREEN);
	rankButton->setPos({ 830, 138 });

	Shape* quitButtonState = new Shape[2]{ *MyShape[QUIT_BUTTON], *MyShape[QUIT_BUTTON_HOVER] };
	Button* quitButton = new QuitButton(quitButtonState);
	quitButton->setPos({ 1000, 10 });

	addButton(newGameButton);
	addButton(loadGameButton);
	addButton(rankButton);
	addButton(quitButton);
}