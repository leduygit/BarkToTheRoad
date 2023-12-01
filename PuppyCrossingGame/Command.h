#pragma once
#include "Map.h"
#include "Character.h"
#include "Sound.h"
class Command
{
public:
	virtual void execute(Character& c, Map& m) {}
	virtual bool isValidMove(Character& c, Map& m) = 0;
	virtual std::string getType() {
		return "move";
	}
};

