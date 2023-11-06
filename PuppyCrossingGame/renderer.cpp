#include "renderer.h"

void Renderer::clear_screen() {
	unsigned int* pixels = m_rs.getMemoryPointer();
	for (int x = 0; x < m_rs.getWidth(); x++) {
		for (int y = 0; y < m_rs.getHeight(); y++) {
			*pixels++ = 0xFFFFFFFF;
		}
	}
}

void Renderer::draw_rect(RECT r, unsigned int color) {
	for (int y = max(0, r.top); y <= min(r.bottom, WINDOW_HEIGHT - 1); y++) {
		unsigned int* pixels = m_rs.getMemoryPointer() + r.left + y * m_rs.getWidth();
		for (int x = max(0, r.left); x <= min(r.right, WINDOW_WIDTH - 1); x++) {
			*pixels++ = color;
		}
	}
}