#pragma once
#include "Lane.h"
#include "AsphaltLane.h"
#include "GrassLane.h"
#include "RailLane.h"
#include "RiverLane.h"

class LaneFactory
{
public:
	//	Lane(const COORD &pos, std::string file_name, ObstacleFactory* fact);
	virtual Lane* createLane(const COORD &pos) = 0;
	virtual std::string getType() {
		return "base";
	};
private:
};

class SpringLaneFactory : public LaneFactory
{
public:
	Lane* createLane(const COORD &pos) override;
	std::string getType() {
		return "spring";
	}
};

class SummerLaneFactory : public LaneFactory
{
public:
	Lane* createLane(const COORD &pos) override;
	std::string getType() {
		return "summer";
	}
};

class WinterLaneFactory
{
public:
	Lane* createLane(const COORD &pos);
};


