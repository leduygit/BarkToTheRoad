#include "ObstacleFactory.h"

int randomInt(int l, int r)
{
	return l + rand() % (r - l + 1);
}

Obstacle* AsphaltObstacleFactory::createObstacle(const COORD &pos)
{
    // pos = position of the lane

    int x = randomInt(0, 1000);
    x %= 2;
    // index of the Obstacle

    if (x == 0) {
        if (pos.X < 200)
            return new BusObstacle({ static_cast<short>( pos.X - 120), pos.Y });
        else 
            return new BusObstacle({ static_cast<short>(pos.X + 1400), pos.Y }, 1);
    }
    else {
        if (pos.X < 200)
            return new CarObstacle({static_cast<short>( pos.X - 120), pos.Y });
        else
            return new CarObstacle({static_cast<short>( pos.X + 1400), pos.Y }, 1);
    }
    return nullptr;
}

Obstacle* GrassObstacleFactory::createObstacle(const COORD &pos) {
    return new GrassObstacle(pos);
}

Obstacle* RailObstacleFactory::createObstacle(const COORD &pos) {
    if (pos.X < 200)
        return new TrainObstacle({ static_cast<short>(pos.X - 4000), pos.Y });
    else 
        return new TrainObstacle({ static_cast<short>(pos.X + 4000), pos.Y }, 1);
}

Obstacle* RiverObstacleFactory::createObstacle(const COORD &pos)
{
    if (pos.X < 200)
        return new RaftObstacle({ static_cast<short>(pos.X - 100), pos.Y });
    else
        return new RaftObstacle({ static_cast<short>(pos.X + 100), pos.Y });
}
