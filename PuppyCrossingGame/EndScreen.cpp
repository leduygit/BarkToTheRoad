#include "EndScreen.h"

EndScreen::EndScreen()
{
	setBackground(MyShape[BACKGROUND_EMPTY]);
	m_e = new Entity{ {50, 50}, MyShape[GHOST]};
	m_vehicle = new Entity{ {1000, 50}, MyShape[CAR_LEFT] };
	m_vehicle->move({ 100, 50 });
}

void EndScreen::render()
{
	m_background->render(0, 0);
	m_e->render();
	m_vehicle->render();
}
