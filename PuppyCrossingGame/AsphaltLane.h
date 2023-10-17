#pragma once
#include "Lane.h"
class AsphaltLane : public Lane
{
public:
	AsphaltLane() = default;
	AsphaltLane(COORD pos, std::string file_name) {
		m_position = pos;
		m_shape = Shape{ file_name };
	}

	using Lane::render;
private:
};

