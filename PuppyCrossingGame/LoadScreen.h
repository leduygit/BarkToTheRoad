#pragma once
#include "Screen.h"
class LoadScreen : public Screen
{
public:
	LoadScreen(Gameplay* gp);
	void updateContent();
private:
	int m_loadPos = -1;
};

