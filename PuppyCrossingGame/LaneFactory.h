#pragma once
#include "Lane.h"
#include "AsphaltLane.h"
#include "GrassLane.h"
#include "RailLane.h"
#include "RiverLane.h"

class LaneFactory
{
public:
	//	Lane(COORD pos, std::string file_name, ObstacleFactory* fact);
	virtual Lane* createLane(COORD pos) = 0;
private:
};

class SpringLaneFactory : public LaneFactory
{
public:
	Lane* createLane(COORD pos) override;
};

class SummerLaneFactory : public LaneFactory
{
public:
	Lane* createLane(COORD pos) override;
};

class WinterLaneFactory
{
public:
	Lane* createLane(COORD pos);
};


