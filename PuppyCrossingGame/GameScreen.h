#pragma once
#include "Screen.h"
#include "Gameplay.h"
class GameScreen: public Screen
{
public:
	GameScreen() = default;
	GameScreen(Gameplay* gp) : m_gameplay{ gp } {}
	void render() override;
private:
	Gameplay* m_gameplay{ nullptr };
};

