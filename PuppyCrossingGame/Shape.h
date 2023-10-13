#pragma once

#define SPRITE_SIZE 30

class Shape
{
private:
	int m_shape[SPRITE_SIZE][SPRITE_SIZE] = { 0 };
public:
	Shape();
	~Shape();
	void SetShape(int shape[]);
	int getShape();
};

