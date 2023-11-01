#pragma once
#include "Command.h"
class MoveDownCommand : public Command
{
public:
	virtual void execute(Character& c, Map& m);
	virtual bool isValidMove(Character& c, Map& m);
};

