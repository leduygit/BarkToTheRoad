#pragma once
#include <Windows.h>
#include <string>
#include "Global.h"
class Text
{
public:
	Text() = default;
	Text(std::string content, RECT rect) : m_content{ content }, m_rect{ rect } {}

	std::string getContent() const {
		return m_content;
	}

	RECT getRect() const {
		return m_rect;
	}

	void render();

private:
	std::string m_content{ "" };
	RECT m_rect{};
};

