#pragma once
#include "Lane.h"

class AsphaltLane : public Lane
{
public:
    AsphaltLane() = default;
    AsphaltLane(COORD pos, std::string file_name, ObstacleFactory* fact) : 
        Lane(pos, file_name, fact) {}

    using Lane::render;
private:
};
