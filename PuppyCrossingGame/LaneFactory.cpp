#include "LaneFactory.h"

Lane* LaneFactory::createLane(COORD pos)
{
    //	Lane(COORD pos, std::string file_name, ObstacleFactory* fact);
    return nullptr;
}

Lane* SpringLaneFactory::createLane(COORD pos)
{
	int random = randomInt(1, 1000) % 4;
	if (random == 0) return new AsphaltLane(pos);
	else if (random == 1) return new GrassLane(pos);
	else if (random == 2) new RailLane(pos);
	return new RiverLane(pos);
}

Lane* SummerLaneFactory::createLane(COORD pos) {
	int random = randomInt(1, 1000) % 4;
	if (random == 0) return new AsphaltLane(pos);
	else if (random == 1) return new GrassLane(pos);
	else if (random == 2) new RailLane(pos);
	return new RiverLane(pos);
}

Lane* WinterLaneFactory::createLane(COORD pos)
{
	int r = randomInt(1, 1000);
	if (r % 3 == 0) return new AsphaltLane(pos);
	else if (r % 3 == 1) return new GrassLane(pos);

	return new RailLane(pos);
}

