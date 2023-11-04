#pragma once

#include <windows.h>

constexpr int WINDOW_WIDTH = 1280;
constexpr int WINDOW_HEIGHT = 720;

class RenderState
{
    int m_height, m_width;
    void* m_memory; // pointer to the memory adress of the color info;
    BITMAPINFO m_bitmapinfo; // color

public:
    RenderState(int _h = 0, int _w = 0);
    ~RenderState();
    unsigned int* getMemoryPointer(); // get m_memory
    int getWidth();
    int getHeight();
    BITMAPINFO* getBitmapPointer();
};

