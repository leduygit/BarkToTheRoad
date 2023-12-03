#pragma once
#include "Screen.h"
class CreditScreen : public Screen
{
public:
	CreditScreen();
	void render();
private:
	Shape* m_board{};
};