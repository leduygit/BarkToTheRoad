#include "Shape.h"

Shape::Shape(unsigned int shape[][SPRITE_SIZE] = { 0 })
{
	for (int x = 0; x < SPRITE_SIZE; ++x)
		for (int y = 0; y < SPRITE_SIZE; ++y)
			m_shape[x][y] = 0xff00ff;
}

Shape::~Shape()
{
	
}


unsigned int Shape::getShape()
{
	return 0;
}

void Shape::render(int offset_x, int offset_y, int window_width, int window_height, unsigned int* pixel)
{
	for (int y = 0; y < SPRITE_SIZE; ++y)
	{
		unsigned int* changedPixel = pixel + offset_x + (offset_y + y) * window_width;
		for (int x = 0; x < SPRITE_SIZE; ++x)
			*changedPixel++ = m_shape[x][y];
	}
}
