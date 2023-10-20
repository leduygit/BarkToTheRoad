#include "AsphaltLaneFactory.h"

Lane* AsphaltLaneFactory::createLane(COORD pos)
{
    COORD coord({ 0, pos.Y });
    AsphaltObstacleFactory* ptr = new AsphaltObstacleFactory();
    return new AsphaltLane(coord, "image/railway_lane.txt", new AsphaltObstacleFactory());
}
