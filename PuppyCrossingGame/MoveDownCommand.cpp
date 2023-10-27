#include "MoveDownCommand.h"

void MoveDownCommand::execute(Character& c)
{
	COORD currentPostition = c.getPos();
	c.move({ static_cast<short>(currentPostition.X), static_cast<short> (currentPostition.Y - 90) });

}
