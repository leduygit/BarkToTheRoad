#include "SpringLaneFactory.h"

Lane* SpringLaneFactory::createLane(COORD pos, std::string file_name, ObstacleFactory* fact)
{
	int random = randomInt(1, 1000);
	if (random % 3 == 0) return new AsphaltLane(pos, file_name, fact);
	else if (random % 3 == 1) return new GrassLane(pos, file_name);

	return new RailLane(pos, file_name, fact);
}
