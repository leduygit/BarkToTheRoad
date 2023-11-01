#include "ObstacleFactory.h"

int randomInt(int l, int r)
{
	int x = l + rand() % (r - l + 1);
	return x;
}

Obstacle* AsphaltObstacleFactory::createObstacle(COORD pos)
{
    // pos = position of the lane

    int x = 0;
    x %= 2;
    // index of the Obstacle

    COORD coord({ 0, pos.Y });



    if (x == 0)
        return new BusObstacle(coord);
    else
        return new CarObstacle(coord);
    return nullptr;
}

Obstacle* GrassObstacleFactory::createObstacle(COORD pos) {
    return new GrassObstacle(pos);
}

Obstacle* RailObstacleFactory::createObstacle(COORD pos) {
    return new TrainObstacle(pos);
}

Obstacle* RiverObstacleFactory::createObstacle(COORD pos)
{
    return new RaftObstacle(pos);
}
