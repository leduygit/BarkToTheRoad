#pragma once

enum ShapeIndex
{
	HCTKCODECAINAY, CAR_RIGHT, GRASS_0,
	GRASS_1, GRASS_2, GRASS_3, GRASS_4,
	STONE, STONE_1, BUSH_2, ROAD, TRAIN_RIGHT
};

extern std::vector<Shape* > MyShape;
void initShape();
