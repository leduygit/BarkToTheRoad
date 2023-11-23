#pragma once
#include "Command.h"
#include "MoveUpCommand.h"
#include "MoveDownCommand.h"
#include "MoveLeftCommand.h"
#include "MoveRightCommand.h"
#include "MouseClickCommand.h"
#include "Map.h"

class InputHandler
{
public:
	InputHandler();

	Command* handleInput(WPARAM key, const Character& c);
private:
	MoveUpCommand* move_up;
	MoveDownCommand* move_down;
	MoveLeftCommand* move_left;
	MoveRightCommand* move_right;
};

