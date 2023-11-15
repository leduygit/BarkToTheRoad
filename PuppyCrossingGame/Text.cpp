#include "Text.h"

void Text::render()
{
	DrawTextA(Global::hdc, m_content.c_str(), -1, &m_rect, DT_NOCLIP | DT_CENTER);
}
