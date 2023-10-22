#pragma once
#include "Command.h"
#include "MoveUpCommand.h"
class InputHandler
{
public:
	InputHandler();

	Command* handleInput(WPARAM key);
private:
	MoveUpCommand* move_up;
};

