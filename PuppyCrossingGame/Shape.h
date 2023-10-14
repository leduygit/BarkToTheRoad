// Shape.h
#pragma once
#include "RenderState.h"

class Shape
{
private:
    unsigned int** m_shape;

public:
    Shape(unsigned int shape[SPRITE_SIZE][SPRITE_SIZE] = nullptr);
    ~Shape();
    void render(int offset_x, int offset_y, RenderState& render_state);
};
