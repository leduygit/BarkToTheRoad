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
	for (int y = r.top; y <= r.bottom; y++) {
		unsigned int* pixels = m_rs.getMemoryPointer() + r.left + y * m_rs.getWidth();
		for (int x = r.left; x <= r.right; x++) {
			*pixels++ = color;
		}
	}
}