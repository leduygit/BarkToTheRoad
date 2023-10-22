#include "Map.h"

LaneFactory* Map::m_fact;

Map::Map(LaneFactory* fact)
{
    m_fact = fact;
}

bool Map::checkCollision(Entity& e)
{
    return false;
}

void Map::render()
{
    for (int i = 0; i < 7; ++i)
        m_lane[i]->render();
}

void Map::addLane()
{
    for (short i = 0; i < 7; ++i)
    {
        m_lane[i] = m_fact->createLane({0 , (SHORT)90 * i });
    }
    return;
}
