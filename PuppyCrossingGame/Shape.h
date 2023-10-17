// Shape.h
#pragma once
#include "RenderState.h"
#include "Global.h"
#include "fstream"

class Shape
{
private:
    /*
    unsigned int** m_shape;
    int m_width;
    int m_height;
    */
    std::string m_fileName;
public:
    Shape(std::string fileName);
    ~Shape();
    void render(int offset_x, int offset_y);
    void loadShapeFromFile(const char* url);
};
