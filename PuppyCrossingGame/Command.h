#pragma once
#include "Map.h"
#include "Character.h"
class Command
{
public:
	virtual void execute(Character& c, Map& m) = 0;
	virtual bool isValidMove(Character& c, Map& m) = 0;
};

