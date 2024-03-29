#include "SaveScreen.h"

SaveScreen::SaveScreen(Gameplay* gp)
{
	setBackground(MyShape[BACKGROUND_EMPTY]);

	Shape* saveGameButtonState = new Shape[2]{ *MyShape[SCORE], *MyShape[SCORE] };
	Button* saveGameButton[3];

	std::vector<std::string> saveFiles;
	std::ifstream saveFile("game_save/name.txt");
	for (std::string line; getline(saveFile, line);)
	{
		saveFiles.push_back(line);
	}

	while (saveFiles.size() < 3) saveFiles.push_back("empty");

	saveFile.close();

	//std::string saveName = gp->getSaveName();
	for (int i = 0; i < 3; ++i)
	{
		saveGameButton[i] = new SaveGameButton(saveGameButtonState, gp, m_render_dialog, saveFiles[3 - i - 1]);
		saveGameButton[i]->setPos({ 500, 200 + static_cast<short>(i) * 100 });
		saveGameButton[i]->setLine(3 - i - 1);
		if (m_savePos == -1) m_savePos = getSize();
		addButton(saveGameButton[i]);

		RECT tmp;
		int height, width;
		saveGameButtonState->getSize(width, height);
		tmp.left = 500;
		tmp.top = 260 + static_cast<short>(i) * 100;
		tmp.right = tmp.left + width;
		addText(new Text{ saveFiles[i], tmp});
	}

	Shape* backButtonState = new Shape[2]{ *MyShape[QUIT_BUTTON], *MyShape[QUIT_BUTTON_HOVER] };
	Button* backButton = new ChangeScreenButton(backButtonState, GAME_SCREEN);
	backButton->setPos({ 1000, 10 });
	addButton(backButton);
}

void SaveScreen::updateContent()
{
	clearText();
	Shape* loadGameButtonState = new Shape[2]{ *MyShape[SCORE], *MyShape[SCORE] };

	std::vector<std::string> saveFiles;
	std::ifstream saveFile("game_save/name.txt");
	for (std::string line; getline(saveFile, line);)
	{
		saveFiles.push_back(line);
	}

	while (saveFiles.size() < 3) saveFiles.push_back("empty");

	saveFile.close();

	for (int i = 0; i < 3; ++i)
	{
		m_buttons[m_savePos + i]->setFileName(saveFiles[3 - i - 1]);

		RECT tmp;
		int height, width;
		loadGameButtonState->getSize(width, height);
		tmp.left = 500;
		tmp.top = 260 + static_cast<short>(i) * 100;
		tmp.right = tmp.left + width;
		addText(new Text{ saveFiles[i], tmp });
	}
}
