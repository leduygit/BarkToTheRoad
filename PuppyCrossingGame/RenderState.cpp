#include "RenderState.h"
#include "assert.h"

#include <memoryapi.h>
RenderState::RenderState(int _h, int _w)
{
    m_height = _h;
    m_width = _w;
    int sz = m_width * m_height * 8;

    // No need to check if m_memory is nullptr, as it's initialized as nullptr.
    m_memory = VirtualAlloc(0, sz, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE); // Use malloc to allocate memory

    m_bitmapinfo.bmiHeader.biSize = sizeof(m_bitmapinfo.bmiHeader);
    m_bitmapinfo.bmiHeader.biWidth = m_width;
    m_bitmapinfo.bmiHeader.biHeight = m_height;
    m_bitmapinfo.bmiHeader.biPlanes = 1;
    m_bitmapinfo.bmiHeader.biBitCount = 32;
    m_bitmapinfo.bmiHeader.biCompression = BI_RGB;
}


RenderState::~RenderState()
{
    VirtualFree(m_memory, 0, MEM_RELEASE);
}

RenderState& RenderState::operator=(const RenderState& _other)
{
    // TODO: insert return statement here
    m_height = _other.m_height;
    m_width = _other.m_width;
    // allocate memory
    int sz = m_width * m_height * 8;
    m_memory = VirtualAlloc(0, sz, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE); // Use malloc to allocate memory
    // copy memory
    memcpy(m_memory, _other.m_memory, sz);
    // copy bitmap info
    m_bitmapinfo = _other.m_bitmapinfo;
    return *this;
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
