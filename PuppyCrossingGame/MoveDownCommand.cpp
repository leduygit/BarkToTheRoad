#include "MoveDownCommand.h"

void MoveDownCommand::execute(Character& c, Map& m)
{
	COORD currentPostition = c.getPos();
	COORD newPosition = { static_cast<short>(currentPostition.X), static_cast<short> (currentPostition.Y - 90) };
	if (m.isRiverLane(newPosition))
	{
		c.setPos(newPosition);
		newPosition = m.jumpOnRaft(c);
		c.setPos(currentPostition);
		c.move(newPosition);
	}
	else {
		short roundedNumberX = (currentPostition.X / 90.0 - std::floor(currentPostition.X / 90.0)) < 0.5 ? std::floor(currentPostition.X / 90.0) : std::ceil(currentPostition.X / 90.0);
		short roundedNumberY = (currentPostition.Y / 90.0 - std::floor(currentPostition.Y / 90.0)) < 0.5 ? std::floor(currentPostition.Y / 90.0) : std::ceil(currentPostition.Y / 90.0);
		COORD newPos = { static_cast<short>(roundedNumberX * 90), static_cast<short> (roundedNumberY * 90 - 90) };
		newPos.X = (newPos.X + 89) / 90 * 90;
		newPos.Y = (newPos.Y + 89) / 90 * 90;
		c.move(newPos);
		//c.move({ static_cast<short>(roundedNumberX * 90), static_cast<short> (roundedNumberY * 90 - 90) });
	}
	SoundTrack::playSound(L"resources/sound/jump.wav", L"alias_3");
}

bool MoveDownCommand::isValidMove(Character& c, Map& m)
{
	c.setPos({ c.getPos().X, static_cast<short>(c.getPos().Y - 90) });
	bool is_collision = m.checkCollisionWithStaticObstacle(c);
	c.setPos({ c.getPos().X, static_cast<short>(c.getPos().Y + 90) });

	return !is_collision;
}
