#include "SettingScreen.h"

SettingScreen::SettingScreen(): m_board{MyShape[SETTING_WINDOW]}
{
	setBackground(MyShape[BACKGROUND_EMPTY]);

	Shape* homeButtonState = new Shape[2]{ *MyShape[HOME], *MyShape[HOME_HOVER] };
	Button* homeButton = new ChangeScreenButton{ homeButtonState, MENU_SCREEN };
	homeButton->setPos({ 570, 220 });

	Shape* speakerButtonState = new Shape[2]{ *MyShape[SPEAKER], *MyShape[SPEAKER_HOVER] };
	Shape* muteButtonState = new Shape[2]{ *MyShape[MUTE], *MyShape[MUTE_HOVER] };
	m_music = new ChangeSoundButton{ speakerButtonState, Global::is_music_muted };
	m_music->setPos({ 450, 300 });
	m_music_muted = new ChangeSoundButton{ muteButtonState, Global::is_music_muted };
	m_music_muted->setPos({ 450, 300 });

	m_sound = new ChangeSoundButton{ speakerButtonState, Global::is_sound_muted };
	m_sound->setPos({ 700, 300 });
	m_sound_muted = new ChangeSoundButton{ muteButtonState, Global::is_sound_muted };
	m_sound_muted->setPos({ 700, 300 });

	addButton(m_music);
	addButton(m_music_muted);
	addButton(m_sound);
	addButton(m_sound_muted);
	addButton(homeButton);
}

void SettingScreen::render()
{
	m_background->render(0, 0);
	m_board->render(350, 190);

	auto buttons = getButtons();
	if (!Global::is_music_muted) {
		buttons[0]->render();
	}
	else {
		buttons[1]->render();
	}

	if (!Global::is_sound_muted) {
		buttons[2]->render();
	}
	else {
		buttons[3]->render();
	}
	buttons[4]->render();
}
