#pragma once
#include "Command.h"
class InputHandler
{
public:
	Command* handleInput(WPARAM key);
	void set_move_up(Command* c) {
		move_up = c;
	}
private:
	Command* move_up;
	Command* move_down;
	Command* move_left;
	Command* move_right;
	Command* change_skin;
	Command* pause;
};

