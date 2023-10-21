#include "SpringLaneFactory.h"

Lane* SpringLaneFactory::createLane(COORD pos)
{
	int random = randomInt(1, 1000);
	if (random % 3 == 0) return new AsphaltLane(pos);
	else if (random % 3 == 1) return new GrassLane(pos);

	return new RailLane(pos);
}
