#pragma once
#include "Map.h"
#include "Character.h"
#include "Screen.h"
class Command
{
public:
	virtual void execute(Character& c, Map& m) {}
	virtual void execute(Screen& s) {}
	virtual bool isValidMove(Character& c, Map& m) = 0;
};

