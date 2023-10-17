#include "AsphaltObstacleFactory.h"

Obstacle* AsphaltObstacleFactory::createObstacle()
{
    int x = randomInt(0, 1000);
    x %= 2;
    
    COORD coord;
    coord.X = randomInt(0, 1000);
    coord.Y = randomInt(0, 1000);

    if (x == 0)
        return new BusObstacle(coord);
    else
        return new CarObstacle(coord);
    return nullptr;
}
