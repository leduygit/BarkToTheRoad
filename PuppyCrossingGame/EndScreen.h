#pragma once
#include "Screen.h"
class EndScreen : public Screen
{
public:
	EndScreen();
	void render() override;
private:
	Entity* m_e{ nullptr };
	Entity* m_vehicle{ nullptr };
};

