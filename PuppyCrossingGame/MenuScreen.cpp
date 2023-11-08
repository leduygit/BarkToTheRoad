#include "MenuScreen.h"
MenuScreen::MenuScreen() {
	setBackground(MyShape[BACKGROUND]);
	// add multiple button states!!!
	Shape* buttonState = new Shape[3]{ *MyShape[CAR_RIGHT], *MyShape[RIVER], *MyShape[TRAIN_RIGHT] };
	Button* newGameButton = new ChangeScreenButton(buttonState, MENU);
	addButton(newGameButton);

	std::vector<Button*> buttons = getButtons();
	for (int i = 0; i < (int)buttons.size(); i++) {
		buttons[i]->setPos({ static_cast<short>(120 * i), 400 });
	}
}