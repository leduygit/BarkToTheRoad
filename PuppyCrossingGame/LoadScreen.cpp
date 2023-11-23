#include "LoadScreen.h"

LoadScreen::LoadScreen(Gameplay* gp)
{
	setBackground(MyShape[BACKGROUND]);

	Shape* loadGameButtonState = new Shape[2]{ *MyShape[LOAD_GAME_BUTTON], *MyShape[LOAD_GAME_BUTTON_HOVER] };
	Button* loadGameButton[3];

	for (int i = 0; i < 3; ++i)
	{
		loadGameButton[i] = new LoadGameButton(loadGameButtonState, gp);
		loadGameButton[i]->setPos({ 500, 200 + static_cast<short>(i) * 100 });
		addButton(loadGameButton[i]);
	}

	Shape* backButtonState = new Shape[2]{ *MyShape[QUIT_BUTTON], *MyShape[QUIT_BUTTON_HOVER] };
	Button* backButton = new ChangeScreenButton(backButtonState, MENU_SCREEN);
	backButton->setPos({ 900, 10 });
	addButton(backButton);


}
