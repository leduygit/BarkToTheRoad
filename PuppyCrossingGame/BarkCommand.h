#pragma once
#include "Command.h"
#include "Sound.h"
class BarkCommand : public Command
{
private:
	SoundTrack m_sound{L"", L"" };
public:
	BarkCommand();
	void execute(Character& c, Map& m) override;
	bool isValidMove(Character& c, Map& m) override;
};

