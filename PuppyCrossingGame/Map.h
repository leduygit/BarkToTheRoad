#pragma once
#include "LaneFactory.h"
#include "Character.h"

constexpr int MAX_LANE = 13;

class Map
{
private:
	int m_lane_number{ 10 };
	std::vector<Lane*> m_lane{ MAX_LANE };
	static LaneFactory* m_fact;
public:
	Map() = default;
	Map(LaneFactory* fact);
  
	bool checkCollision(Character& e);
	bool checkCollisionWithStaticObstacle(Character& e);
	void moveObstacle(Character &c);
	void addObstacle();
	void removeObstacle();
	void update(int& offset);
	COORD jumpOnRaft(Character &c);

	bool isRiverLane(COORD pos);

	void render(int offset = 0);
	void addLane();

	// load game from file
	void loadGame(std::ifstream& fin);

	// save game to file
	void saveGame(std::ofstream& fout);
};

