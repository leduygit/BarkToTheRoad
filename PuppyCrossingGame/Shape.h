#pragma once

#define SPRITE_SIZE 90

class Shape
{
private:
	unsigned int m_shape[SPRITE_SIZE][SPRITE_SIZE] = { 0 };
public:
	Shape(unsigned int shape[][SPRITE_SIZE]);
	~Shape();
	unsigned int getShape();
	void render(int offset_x, int offset_y, int width, int height, unsigned int* pixel);
};

