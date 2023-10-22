#pragma once
#include "Command.h"
class MoveUpCommand: public Command
{
public:
	virtual void execute(Character& c);
};

