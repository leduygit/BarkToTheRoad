#pragma once

#include "Screen.h"
class SaveScreen : public Screen
{
public:
	SaveScreen(Gameplay* gp);

	void updateContent();

private:
	bool m_render_dialog{ true };
	int m_savePos = -1;
};

