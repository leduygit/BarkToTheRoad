#pragma once
#include "Command.h"
#include "Screen.h"
class MouseClickCommand : public Command
{
public:
	void execute(Screen& s);
};

