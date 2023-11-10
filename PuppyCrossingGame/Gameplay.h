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
#include "Button.h"
#include "ScreenRegistry.h"

class Gameplay
{
public:
	InputHandler ih;
	Command* command;
	Character* character;
	SummerLaneFactory fact;
	Map m;
	
	Gameplay();
	~Gameplay();
	void gameLogic();
	void setOffset(int *offset) {
		m_offset = offset;
	}

	bool isEnd();

private:
	int *m_offset{ nullptr };
};

