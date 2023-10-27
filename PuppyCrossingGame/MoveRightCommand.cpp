#include "MoveRightCommand.h"

void MoveRightCommand::execute(Character& c)
{
	COORD currentPostition = c.getPos();
	c.move({ static_cast<short>(currentPostition.X + 90), static_cast<short> (currentPostition.Y) });

}
