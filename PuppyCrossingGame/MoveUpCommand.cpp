#include "MoveUpCommand.h"

void MoveUpCommand::execute(Character& c)
{
	COORD currentPostition = c.getPos();
	c.move({ static_cast<short>(currentPostition.X), static_cast<short> (currentPostition.Y + 90) });
}
