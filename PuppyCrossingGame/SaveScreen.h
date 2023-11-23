#pragma once

#include "Screen.h"
class SaveScreen : public Screen
{
public:
	SaveScreen(Gameplay* gp);

private:
	bool m_render_dialog{ true };
};

