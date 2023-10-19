// Shape.h
#pragma once
#include "RenderState.h"
#include "Global.h"
#include "fstream"

class Shape
{
private:
    unsigned int** m_shape;
    int m_width;
    int m_height;
    //std::string m_fileName;
public:
    Shape() = default;
    Shape(std::string fileName);
    ~Shape();
    void render(int offset_x, int offset_y);
    void loadShapeFromFile(const char* url);
    void set_file_name(std::string file_name) {
        //m_fileName = file_name;
    }

    void getSize(int& width, int& height);
};
