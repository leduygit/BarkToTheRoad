#include "MoveUpCommand.h"

void MoveUpCommand::execute(Character& c, Map& m)
{
	COORD currentPostition = c.getPos();
	COORD newPosition = { static_cast<short>(currentPostition.X), static_cast<short> (currentPostition.Y + 90) };
	if (m.isRiverLane(newPosition))
	{
		c.setPos(newPosition);
		newPosition = m.jumpOnRaft(c);
		c.setPos(currentPostition);
		c.move(newPosition);
	}
	else { /*Nam mo a di da phat cau mong moi su thu tha cho doan code ban nay*/
		short roundedNumber = (currentPostition.X / 90.0 - std::floor(currentPostition.X / 90.0)) < 0.5 ? std::floor(currentPostition.X / 90.0) : std::ceil(currentPostition.X / 90.0);
		c.move({ static_cast<short>(roundedNumber * 90), static_cast<short> (currentPostition.Y + 90) });
	}
}

bool MoveUpCommand::isValidMove(Character& c, Map& m)
{
	c.setPos({ c.getPos().X, static_cast<short>(c.getPos().Y + 90) });
	bool is_collision = m.checkCollisionWithStaticObstacle(c);
	c.setPos({ c.getPos().X, static_cast<short>(c.getPos().Y - 90) });

	return !is_collision;
}
