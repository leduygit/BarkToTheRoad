#include "RenderState.h"
#include "assert.h"

RenderState::RenderState(int _h, int _w)
{
    m_height = _h;
    m_width = _w;
    int sz = m_width * m_height * sizeof(unsigned int);

    // No need to check if m_memory is nullptr, as it's initialized as nullptr.
    m_memory = (unsigned int*)malloc(sz); // Use malloc to allocate memory
    if (m_memory == nullptr) {
        assert(0);
        // Handle memory allocation failure, e.g., throw an exception or return an error code.
    }


    m_bitmapinfo.bmiHeader.biSize = sizeof(m_bitmapinfo.bmiHeader);
    m_bitmapinfo.bmiHeader.biWidth = m_width;
    m_bitmapinfo.bmiHeader.biHeight = m_height;
    m_bitmapinfo.bmiHeader.biPlanes = 1;
    m_bitmapinfo.bmiHeader.biBitCount = 32;
    m_bitmapinfo.bmiHeader.biCompression = BI_RGB;
}


RenderState::~RenderState()
{
    //if (m_memory)
    //{
    //    free(m_memory); // Free the allocated memory using free
    //    m_memory = nullptr;
    //}
}


unsigned int* RenderState::getMemoryPointer()
{
    return reinterpret_cast<unsigned int*>(m_memory);
}


int RenderState::getWidth()
{
    return m_width;
}

int RenderState::getHeight()
{
    return m_height;
}

BITMAPINFO* RenderState::getBitmapPointer()
{
    return &m_bitmapinfo;
}
