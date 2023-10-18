// Shape.cpp
#include "Shape.h"

Shape::Shape(std::string fileName) : m_fileName(fileName) {}

Shape::~Shape() {}

void Shape::render(int offset_x, int offset_y) {
    std::ifstream ifs(m_fileName);
    int width, height;
    ifs >> width >> height;
    if (!ifs.is_open())
        return;
    for (int x = 0; x < height; x++)
    {
        for (int y = 0; y < width; y++) {
            std::string colorHex;
            ifs >> colorHex;
            unsigned int m_shape;
            if (sscanf_s(colorHex.c_str(), "0x%8X", &m_shape) != 1) {
            }
            if (m_shape != 0x00000000)
                Global::drawer.draw_rect({ offset_x + x, offset_y + y, offset_x + x, offset_y + y }, m_shape);
        }
    }
    ifs.close();
}

void Shape::loadShapeFromFile(const char* url)
{
    /*
    std::ifstream ifs(url);
    if (!ifs.is_open())
        return ;
    for (int i = 0; i < m_height; i++)
    {
        for (int j = 0; j < m_width; j++) {
            std::string colorHex;
            ifs >> colorHex;
            if (sscanf_s(colorHex.c_str(), "0x%8X", &m_shape[i][j]) != 1) {
            }
        }
    }
    */
}

void Shape::getSize(int& width, int& height)
{
    std::ifstream ifs(m_fileName);
    ifs >> width >> height;
    ifs.close();
}
