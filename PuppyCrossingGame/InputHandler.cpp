#include "InputHandler.h"

Command* InputHandler::handleInput(WPARAM key)
{
	switch (key)
	{
	case VK_UP:
		return move_up;
	case VK_DOWN:
		return move_down;
	case VK_LEFT:
		return move_left;
	case VK_RIGHT:
		return move_right;
	default:
		return nullptr;
	}
}
