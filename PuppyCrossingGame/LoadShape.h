#pragma once
#include "Shape.h"

enum ShapeIndex
{
	HCTKCODECAINAY, CAR_RIGHT, GRASS_0,
	GRASS_1, GRASS_2, GRASS_3, GRASS_4,
	STONE, STONE_1, BUSH_2, ROAD, TRAIN_RIGHT, DOG_STAY_1, DOG_STAY_2, DOG_JUMP_1, DOG_JUMP_2, RAIL, LOG, RIVER, RED_LIGHT, GREEN_LIGHT, BACKGROUND
};

extern std::vector<Shape* > MyShape;
void initShape();
