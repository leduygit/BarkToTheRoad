#include "InputHandler.h"

InputHandler::InputHandler() {
	move_up = new MoveUpCommand;
}

Command* InputHandler::handleInput(WPARAM key)
{
	switch (key)
	{
	case VK_UP:
		return move_up;
	default:
		return nullptr;
	}
}
