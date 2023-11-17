#pragma once
#include "ObstacleFactory.h"
#include "vector"
#include "LoadShape.h"
#include "Character.h"
#include "TrafficLight.h"

enum FactoryIndex {
	AsphaltFactory, GrassFactory, RiverFactory, RailFactory	
};

class Lane
{
protected:
	COORD m_position{};
	std::vector<Obstacle*> m_obs;
	TrafficLight m_light;
	short direction{1};
	int m_shapeIndex;
	int m_factoryIndex;
public:
	ObstacleFactory* m_fact;
	Shape m_shape;


	Lane() = default;
	Lane(const COORD &pos);
	Lane(const Lane& lane);
	virtual void render(int offset = 0);
	virtual bool spawnRate();
	virtual void addObstacle();	
	virtual void removeObstacle();
	virtual void moveObstacle();
	virtual bool checkCollision(Character& e);
	virtual void setPos(const COORD &pos);
	COORD getCollision(Character& c);
	virtual void moveObstacle(Character& c) {}
	virtual bool isRiverLane() {
		return false;
	}
	virtual bool isStaticLane() {
		return true;
	}
	void reverseDirection();
	void setFactoryIndex(int index);
	int getFactoryIndex() const;

	friend std::istream& operator>>(std::istream& in, Lane &lane);
	friend std::ostream& operator<<(std::ostream& out, const Lane &lane);
};

