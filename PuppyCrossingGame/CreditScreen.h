#pragma once
#include "Screen.h"
class CreditScreen : public Screen
{
public:
	CreditScreen(int id = 0);
	void render() override;
private:
	Shape* m_board{};
};