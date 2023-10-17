#include "AsphaltObstacleFactory.h"

Obstacle* AsphaltObstacleFactory::createObstacle(COORD pos)
{
    // pos = position of the lane

    int x = randomInt(0, 1000);
    x %= 2;
    // index of the Obstacle

    COORD coord({ 0, pos.Y});



    if (x == 0)
        return new BusObstacle(coord);
    else
        return new CarObstacle(coord);
    return nullptr;
}
