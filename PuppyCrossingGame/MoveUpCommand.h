#pragma once
#include "Command.h"
class MoveUpCommand: public Command
{
public:
	virtual void execute(Character& c, Map& m);
	virtual bool isValidMove(Character& c, Map& m);
};

