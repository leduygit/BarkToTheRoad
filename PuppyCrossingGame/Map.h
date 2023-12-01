#pragma once
#include "LaneFactory.h"
#include "Character.h"

constexpr int MAX_LANE = 15;

enum FactoryType {
	SUMMER,
	SPRING,
	WINTER,
	AUTUMN
};

class Map
{
private:
	int m_lane_number{ 15 };
	std::vector<Lane*> m_lane{ MAX_LANE };
	LaneFactory* m_fact{ nullptr };
	int m_offset = 0;
	int m_factoryType{SUMMER};
public:
	Map() = default;
	~Map();
	Map(LaneFactory* fact);
  	Map& operator=(const Map& m);
	bool checkCollision(Character& e);
	bool checkCollisionWithStaticObstacle(Character& e);
	void moveObstacle(Character &c);
	void addObstacle();
	void removeObstacle();
	void update();
	void updateOffset(int speed);
	COORD jumpOnRaft(Character &c);

	bool isRiverLane(COORD pos);

	void render();
	void addLane();

	// load game from file
	void loadGame(std::ifstream& fin);

	// save game to file
	void saveGame(std::ofstream& fout);

	friend std::istream& operator>>(std::istream& in, Map &m);
	friend std::ostream& operator<<(std::ostream& out, const Map &m);
};

