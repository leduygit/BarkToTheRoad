#pragma once
#include "LaneFactory.h"
#include "Character.h"
class Map
{
private:
	int m_lane_number{ 8 };
	Lane* m_lane[10];
	static LaneFactory* m_fact;
public:
	Map() = default;
	Map(LaneFactory* fact);
  
	bool checkCollision(Character& e);
	bool checkCollisionWithStaticObstacle(Character& e);
	void moveObstacle();
	void addObstacle();
	void removeObstacle();

	void render();
	void addLane();
};

