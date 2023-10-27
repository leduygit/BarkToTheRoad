#pragma once
#include "Command.h"
class MoveDownCommand : public Command
{
public:
	virtual void execute(Character& c);
};

