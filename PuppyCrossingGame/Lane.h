#pragma once
#include "ObstacleFactory.h"
#include "vector"
#include "LoadShape.h"
#include "Character.h"
#include "TrafficLight.h"

class Lane
{
protected:
	COORD m_position{};
	int m_obsSize = 0;
	std::vector<Obstacle*> m_obs;
	TrafficLight m_light;
public:
	ObstacleFactory* m_fact;
	Shape m_shape;


	Lane() = default;
	Lane(const COORD &pos);
	virtual void render();
	virtual void addObstacle();	
	virtual void removeObstacle();
	virtual void moveObstacle();
	virtual bool checkCollision(Character& e);
	COORD getCollision(Character& c);
	virtual void moveObstacle(Character& c) {}
	virtual bool isRiverLane() {
		return false;
	}
	virtual bool isStaticLane() {
		return true;
	}
};

