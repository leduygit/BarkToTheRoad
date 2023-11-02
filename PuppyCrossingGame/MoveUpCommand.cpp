#include "MoveUpCommand.h"

void MoveUpCommand::execute(Character& c, Map& m)
{
	COORD currentPostition = c.getPos();
	COORD newPosition = { static_cast<short>(currentPostition.X), static_cast<short> (currentPostition.Y + 90) };
	c.setPos(newPosition);
	newPosition = m.jumpOnRaft(c);
	c.setPos(currentPostition);
	c.move(newPosition);
}

bool MoveUpCommand::isValidMove(Character& c, Map& m)
{
	c.setPos({ c.getPos().X, static_cast<short>(c.getPos().Y + 90) });
	bool is_collision = m.checkCollisionWithStaticObstacle(c);
	c.setPos({ c.getPos().X, static_cast<short>(c.getPos().Y - 90) });

	return !is_collision;
}
