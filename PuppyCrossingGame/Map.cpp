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
        if (m_lane[i]->checkCollision(e) && !m_lane[i]->isStaticLane()) return true;
    }
    return false;
}

void Map::moveObstacle(Character &c)
{
    for (int i = 0; i < m_lane_number; ++i) {
        m_lane[i]->moveObstacle();
        m_lane[i]->moveObstacle(c);
    }
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

COORD Map::jumpOnRaft(Character &c)
{
    COORD pos = c.getPos();
    for (SHORT k = -30; k <= 60; k+= 90) {
        c.setPos({ pos.X + k, pos.Y });
        for (int i = 0; i < m_lane_number; ++i)
        {
            if (m_lane[i]->isRiverLane())
            {
                COORD pos = m_lane[i]->getCollision(c);
                COORD dummy = { -1, -1 };
                if (!(pos == dummy))
                    return { pos.X + 40, pos.Y };
            }
        }
    }
    return pos;
}

bool Map::isRiverLane(COORD pos)
{
    return m_lane[pos.Y / 90]->isRiverLane();
}

void Map::render()
{
    for (int i = 0; i < m_lane_number; ++i)
        m_lane[i]->render();
}

void Map::addLane()
{
    m_lane[0] = new GrassLane({ 0, static_cast<short>(0) });
    for (short i = 1; i < m_lane_number; ++i)
    {
        m_lane[i] = m_fact->createLane({ 0 , static_cast<short>(90 * i) });
    }
    return;
}
