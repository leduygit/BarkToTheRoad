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

class Gameplay
{
public:
	InputHandler ih;
	Command* command;
	Character* character;
	SummerLaneFactory fact;
	Map m;

	bool haveStarted = false;

	Gameplay();
	~Gameplay();
	void render();
	void gameLogic();
	void setPause(bool pause) {
		m_is_paused = pause;
	}
	bool isStart();
	bool isEnd();
	int getScore() const;
	void saveGame() const;
	void loadGame(std::string fileName);
private:
	int m_score{ 0 };
	int m_speed = 0;
	bool m_is_paused{ true };
};

