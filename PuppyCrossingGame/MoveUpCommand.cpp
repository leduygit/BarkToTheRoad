#include "MoveUpCommand.h"

void MoveUpCommand::execute(Character& c)
{
	COORD currentPostition = c.getPos();
	c.move({ static_cast<short>(currentPostition.X), static_cast<short> (currentPostition.Y + 90) });
}

bool MoveUpCommand::isValidMove(Character& c, Map& m)
{
	c.setPos({ c.getPos().X, static_cast<short>(c.getPos().Y + 90) });
	bool is_collision = m.checkCollision(c);
	c.setPos({ c.getPos().X, static_cast<short>(c.getPos().Y - 90) });

	return !is_collision;
}
