#pragma once

#include "RenderState.h"
#include <wtypes.h>

class Renderer {
public:
	Renderer(RenderState& rs) : m_rs(rs) {}
	void set_render_state(RenderState& rs) {
		m_rs = rs;
	}
	void clear_screen();
	void draw_rect(RECT r, unsigned int color);

private:
	RenderState& m_rs;
};