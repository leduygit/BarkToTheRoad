#pragma once
#include "Character.h"
class Command
{
public:
	virtual void execute(Character& c) = 0;
};

