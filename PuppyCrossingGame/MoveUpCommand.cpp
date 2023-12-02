#include "MoveUpCommand.h"

void MoveUpCommand::execute(Character& c, Map& m)
{
	COORD currentPostition = c.getPos();
	COORD newPosition = { static_cast<short>(currentPostition.X), static_cast<short> (currentPostition.Y + 90) };
	newPosition.X = (newPosition.X + 89) / 90 * 90;
	newPosition.Y = (newPosition.Y + 89) / 90 * 90;
	c.move(newPosition);
	SoundTrack::playSound(L"resources/sound/jump.wav", L"alias_3");
}

bool MoveUpCommand::isValidMove(Character& c, Map& m)
{
	COORD currentPostition = c.getPos();
	COORD newPosition = { static_cast<short>(currentPostition.X), static_cast<short> (currentPostition.Y + 90) };
	newPosition.X = (newPosition.X + 89) / 90 * 90;
	newPosition.Y = (newPosition.Y + 89) / 90 * 90;
	c.setPos(newPosition);
	bool is_collision = m.checkCollisionWithStaticObstacle(c);
	c.setPos(currentPostition);

	return !is_collision;
}
