#pragma once
#include "Command.h"
class MoveLeftCommand : public Command
{
public:
	virtual void execute(Character& c);
};

