#include "BarkCommand.h"

BarkCommand::BarkCommand() : m_sound{ L"resources/sound/bark.wav", L"alias_2" } {}

void BarkCommand::execute(Character& c, Map& m)
{
	SoundTrack::playSound(L"resources/sound/bark.wav", L"alias_bark");
}
bool BarkCommand::isValidMove(Character& c, Map& m)
{
	return true;
}

