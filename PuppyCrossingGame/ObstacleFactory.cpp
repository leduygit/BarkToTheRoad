#include "ObstacleFactory.h"

int randomInt(int l, int r)
{
	return l + rand() % (r - l + 1);
}

Obstacle* AsphaltObstacleFactory::createObstacle(const COORD &pos)
{
    // pos = position of the lane

    int x = 0;
    x %= 2;
    // index of the Obstacle

    COORD coord({ -120, pos.Y });



    if (x == 0)
        return new BusObstacle(coord);
    else
        return new CarObstacle(coord);
    return nullptr;
}

Obstacle* GrassObstacleFactory::createObstacle(const COORD &pos) {
    return new GrassObstacle(pos);
}

Obstacle* RailObstacleFactory::createObstacle(const COORD &pos) {
    return new TrainObstacle({ static_cast<short>(pos.X - 300), pos.Y });
}

Obstacle* RiverObstacleFactory::createObstacle(const COORD &pos)
{
    return new RaftObstacle({ static_cast<short>(pos.X - 100), pos.Y });
}
