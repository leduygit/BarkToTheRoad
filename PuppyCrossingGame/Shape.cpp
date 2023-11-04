// Shape.cpp
#include "Shape.h"

bool operator==(const COORD& p1, const COORD& p2)
{
    return p1.X == p2.X && p1.Y == p2.Y;
}

bool isInside(const COORD &pos)
{
    if (pos.X > WINDOW_WIDTH) 
        return false;
    return true;
}

Shape::Shape(std::string fileName)
{
    std::ifstream ifs(fileName);
    if (!ifs.is_open())
        return ;
    ifs >> m_width >> m_height;
    m_shape = new unsigned int* [m_height];
    for (int i = 0; i < m_height; i++)
    {
        m_shape[i] = new unsigned int[m_width];
        for (int j = 0; j < m_width; j++) {
            std::string colorHex;
            ifs >> colorHex;
            if (sscanf_s(colorHex.c_str(), "0x%8X", &m_shape[i][j]) != 1) {
            }
        }
    }
    ifs.close();
}

Shape::~Shape() {}

void Shape::render(int offset_x, int offset_y) {
    for (int x = 0; x < m_height; x++)
    {
        for (int y = 0; y < m_width; y++) {
            if (m_shape[x][y] != 0x00000000)
                Global::drawer.draw_rect({ offset_x + y, offset_y + m_height - x - 1, offset_x + y, offset_y + m_height - x - 1 }, m_shape[x][y]);
        }
    }
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
    width = m_width;
    height = m_height;
}
