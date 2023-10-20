#include "SummerLaneFactory.h"
#include "AsphaltLane.h"
#include "GrassLane.h"
#include "RailLane.h"
Lane* SummerLaneFactory::createLane(COORD pos, std::string file_name, ObstacleFactory* fact) {
	int r = randomInt(1, 1000);
	if (r % 3 == 0) return new AsphaltLane(pos, file_name, fact);
	else if (r % 3 == 1) return new GrassLane(pos, file_name);

	return new RailLane(pos, file_name, fact);
}