#include "WinterLaneFactory.h"

Lane* WinterLaneFactory::createLane(COORD pos)
{
	int r = randomInt(1, 1000);
	if (r % 3 == 0) return new AsphaltLane(pos);
	else if (r % 3 == 1) return new GrassLane(pos);

	return new RailLane(pos);
}
