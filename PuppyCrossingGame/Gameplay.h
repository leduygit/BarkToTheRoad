#pragma once
#include "AsphaltLane.h"
#include "Character.h"
#include "Entity.h"
#include "Global.h"
#include "GrassLane.h"
#include "InputHandler.h"
#include "Map.h"
#include "MoveUpCommand.h"
#include "RailLane.h"
#include "RenderState.h"
#include "Shape.h"
#include "renderer.h"
#include "external/encrypt.h"

class Gameplay
{
public:
	InputHandler ih{};
	Command* command{ nullptr };
	Character* character{nullptr};
	LaneFactory* fact;
	Map m{};

	bool haveStarted = false;

	Gameplay();
	~Gameplay();
	void render();
	void newGame();
	void gameLogic();
	void setPause(bool pause) {
		m_is_paused = pause;
	}
	bool isStart();
	bool isEnd();
	void exportScore();
	void handleEndGame();
	int getScore() const;
	std::string& getUserName() {
		return m_user_name;
	}
	bool getIsNewGame() const;
	bool getEnded() const;
	bool vehicleArrived();
	void saveGame(std::string fileName) const;
	void loadGame(std::string fileName);
	void setIsNewGame(bool is_new_game);
private:
	int m_score{ 0 };
	int m_speed = 0;
	bool m_is_paused{ true };
	std::string m_user_name{ "" };
	std::string m_key{ "" };
	bool m_is_new_game{ true };
	FactoryType m_fact_type{ SUMMER };
	Entity* m_vehicle{ nullptr };
	bool m_ended{ false };
};

