// Shape.cpp
#include "Shape.h"

Shape::Shape(unsigned int shape[SPRITE_SIZE][SPRITE_SIZE])
{
    // Initialize m_shape as a dynamic 2D array
    m_shape = new unsigned int* [SPRITE_SIZE];
    for (int x = 0; x < SPRITE_SIZE; ++x)
    {
        m_shape[x] = new unsigned int[SPRITE_SIZE];
        for (int y = 0; y < SPRITE_SIZE; ++y)
            m_shape[x][y] = shape ? shape[x][y] : 0xFF00FF; // Set the color to purple if shape is not provided
    }
}

Shape::~Shape()
{
    // Deallocate the dynamically allocated memory (2D array)
    for (int i = 0; i < SPRITE_SIZE; i++) {
        delete[] m_shape[i];
    }
    delete[] m_shape;
}

void Shape::render(int offset_x, int offset_y, RenderState& render_state)
{
    unsigned int* pixel = render_state.getMemoryPointer();
    int window_width = render_state.getWidth();
    for (int y = 0; y < SPRITE_SIZE; ++y)
    {
        unsigned int* changedPixel = pixel + offset_x + (offset_y + y) * window_width;
        for (int x = 0; x < SPRITE_SIZE; ++x)
            *changedPixel++ = m_shape[x][y];
    }
}
