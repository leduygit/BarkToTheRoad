#pragma once
#include "Lane.h"
#include "ObstacleFactory.h"

class AsphaltLane : public Lane
{
public:
    AsphaltLane() = default;
    AsphaltLane(const COORD &pos) : 
        Lane(pos)
    {
        m_fact = new AsphaltObstacleFactory();
        m_shape = *MyShape[ROAD];
        m_shapeIndex = ROAD;
        m_factoryIndex = AsphaltFactory;
    }

    using Lane::render;
private:
};

