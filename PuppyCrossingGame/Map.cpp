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

void Map::moveObstacle()
{
    for (int i = 0; i < 7; ++i)
        m_lane[i]->moveObstacle();
}

void Map::addObstacle()
{
    if (randomInt(0, 100) <= 90) return;
    int id = randomInt(0, 100);
    id %= 7;
    m_lane[id]->addObstacle();
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
        m_lane[i] = m_fact->createLane({ 0 , static_cast<short>(90 * i) });
    }
    return;
}
