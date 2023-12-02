// Shape.cpp
#include "Shape.h"

Shape::Shape(const Shape& s)
    : m_width(s.m_width), m_height(s.m_height)
{
    m_shape = new unsigned int* [m_height];
    for (int i = 0; i < m_height; i++)
    {
        m_shape[i] = new unsigned int[m_width];
        for (int j = 0; j < m_width; j++) {
            m_shape[i][j] = s.m_shape[i][j];
        }
    }
}

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

bool isOutSideRight(const COORD& pos)
{
    return pos.X > WINDOW_WIDTH;
}

bool isOutSideLeft(const COORD& pos)
{
    return pos.X < -900;
}

Shape::Shape(std::string fileName)
{
    /*std::ifstream ifs(fileName);
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
    ifs.close();*/
    std::ifstream ifs(fileName, std::ios::binary);

    ifs.read(reinterpret_cast<char*>(&m_width), sizeof(m_width));
    ifs.read(reinterpret_cast<char*>(&m_height), sizeof(m_height));
    m_shape = new unsigned int* [m_height];
    for (int i = 0; i < m_height; ++i) {
        m_shape[i] = new unsigned int[m_width];
        for (int j = 0; j < m_width; j++) {
            ifs.read(reinterpret_cast<char*>(&m_shape[i][j]), sizeof(m_shape[i][j]));
        }
    }

    ifs.close();
}

Shape& Shape::operator=(const Shape& s)
{
    // TODO: insert return statement here
    if (this == &s)
		return *this;

    for (int i = 0; i < m_height; i++)
        delete[] m_shape[i];
    delete[] m_shape;

    m_width = s.m_width;
    m_height = s.m_height;
    m_shape = new unsigned int* [m_height];
    for (int i = 0; i < m_height; i++)
    {
		m_shape[i] = new unsigned int[m_width];
        for (int j = 0; j < m_width; j++) {
			m_shape[i][j] = s.m_shape[i][j];
		}
	}
    return *this;
}

Shape::~Shape() {
    if (m_shape) {
        for (int i = 0; i < m_height; i++)
            if (m_shape[i])
                delete[] m_shape[i];
        delete[] m_shape;
    }
}

void Shape::render(int offset_x, int offset_y) {
    /*for (int x = 0; x < m_height; x++)
    {
        for (int y = 0; y < m_width; y++) {
            if (m_shape[x][y] != 0x00000000)
                Global::drawer.draw_rect({ offset_x + y, offset_y + m_height - x - 1, offset_x + y, offset_y + m_height - x - 1 }, m_shape[x][y]);
            
        }
    }*/
    unsigned int* pixels = Global::default_render_state.getMemoryPointer();
    for (int x = 0; x < m_height; x++)
    {
        for (int y = 0; y < m_width; y++) {
            if (offset_x + y <= 0 || offset_x + y >= Global::default_render_state.getWidth() || offset_y + m_height - x - 1 <= 0 || offset_y + m_height - x - 1 >= Global::default_render_state.getHeight())
				continue;
			if (m_shape[x][y] != 0x00000000)
				pixels[(offset_x + y) + (offset_y + m_height - x - 1) * Global::default_render_state.getWidth()] = m_shape[x][y];
		}
	}
}

void Shape::getSize(int& width, int& height)
{
    width = m_width;
    height = m_height;
}
