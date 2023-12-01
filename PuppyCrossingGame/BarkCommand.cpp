#include "BarkCommand.h"

BarkCommand::BarkCommand() : m_sound{ L"resources/sound/bark.wav", L"alias_2" } {}

void BarkCommand::execute(Character& c, Map& m)
{
	//MessageBox(NULL, L"Hello!", L"Example", MB_OK | MB_ICONINFORMATION);
	m_sound.playSound();
}
bool BarkCommand::isValidMove(Character& c, Map& m)
{
	return true;
}

std::string BarkCommand::getType()
{
	return "bark";
}

