#include "MoveRightCommand.h"

void MoveRightCommand::execute(Character& c, Map& m)
{
	COORD currentPostition = c.getPos();
	c.setRightDirection();
	c.move({ static_cast<short>(currentPostition.X + 90), static_cast<short> (currentPostition.Y) });
	SoundTrack::playSound(L"resources/sound/jump.wav", L"alias_3");
}

bool MoveRightCommand::isValidMove(Character& c, Map& m)
{
	c.setPos({ static_cast<short>(c.getPos().X + 90), c.getPos().Y });
	bool is_collision = m.checkCollisionWithStaticObstacle(c);
	c.setPos({ static_cast<short>(c.getPos().X - 90), c.getPos().Y });

	return !is_collision;
}
