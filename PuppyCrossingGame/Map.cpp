#include "Map.h"
#define NUM_LANE 8


LaneFactory* Map::m_fact;

Map::Map(LaneFactory* fact)
{
    m_fact = fact;
}

bool Map::checkCollision(Character& e)
{
    for (int i = 0; i < m_lane_number; ++i)
        if (m_lane[i]->checkCollision(e)) return true;
    return false;
}

bool Map::checkCollisionWithStaticObstacle(Character& e)
{
    if (e.getPos().X < 0 || e.getPos().X >= 1260 || e.getPos().Y < 0) return true;
    for (int i = 0; i < m_lane_number; i++) {
        if (m_lane[i]->checkCollision(e) && !m_lane[i]->isValid()) return true;
    }
    return false;
}

void Map::moveObstacle()
{
    for (int i = 0; i < m_lane_number; ++i)
        m_lane[i]->moveObstacle();
}

void Map::addObstacle()
{
    if (randomInt(0, 100) <= 90) return;
    int id = randomInt(0, 100);
    id %= m_lane_number;
    m_lane[id]->addObstacle();
}

void Map::removeObstacle()
{
    for (int i = 0; i < m_lane_number; ++i)
        m_lane[i]->removeObstacle();
}

void Map::render()
{
    for (int i = 0; i < m_lane_number; ++i)
        m_lane[i]->render();
}

void Map::addLane()
{
    for (short i = 0; i < m_lane_number; ++i)
    {
        m_lane[i] = m_fact->createLane({ 0 , static_cast<short>(90 * i) });
    }
    return;
}
