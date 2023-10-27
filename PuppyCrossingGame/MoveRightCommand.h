#pragma once
#include "Command.h"
class MoveRightCommand : public Command
{
public:
	virtual void execute(Character& c);
	virtual bool isValidMove(Character& c, Map& m);
};

