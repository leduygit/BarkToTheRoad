#include "InputHandler.h"

InputHandler::InputHandler() {
	move_up = new MoveUpCommand;
    move_down = new MoveDownCommand;
    move_left = new MoveLeftCommand;
    move_right = new MoveRightCommand;
}

Command* InputHandler::handleInput(WPARAM key, const Character& c)
{
    if (!c.isStanding()) return nullptr;
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
    case WM_LBUTTONUP:
        return left_click;
    default:
        return nullptr;
    }
}
