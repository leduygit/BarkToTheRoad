#include "LoadShape.h"

std::vector<Shape*> MyShape(100);

void initShape() {
	MyShape[CAR_RIGHT] = new Shape{ "resources/image/car_right.bin" };
	MyShape[GRASS_0] = new Shape("resources/image/grass_0.bin");
	MyShape[GRASS_1] = new Shape("resources/image/grass_1.bin");
	MyShape[GRASS_2] = new Shape("resources/image/grass_2.bin");
	MyShape[GRASS_3] = new Shape("resources/image/grass_3.bin");
	MyShape[GRASS_4] = new Shape("resources/image/grass_4.bin");
	MyShape[STONE] = new Shape("resources/image/stone.bin");
	MyShape[STONE_1] = new Shape("resources/image/stone1.bin");
	MyShape[BUSH_2] = new Shape("resources/image/bush2.bin");
	MyShape[ROAD] = new Shape("resources/image/road.bin");
	MyShape[TRAIN_RIGHT] = new Shape("resources/image/train_right.bin");
	MyShape[DOG_STAY_1] = new Shape("resources/image/dog_stay_1.bin");
	MyShape[DOG_STAY_2] = new Shape("resources/image/dog_stay_2.bin");
	MyShape[DOG_JUMP_1] = new Shape("resources/image/dog_jump_1.bin");
	MyShape[DOG_JUMP_2] = new Shape("resources/image/dog_jump_2.bin");
	MyShape[RAIL] = new Shape("resources/image/railway_lane.bin");
	MyShape[LOG] = new Shape("resources/image/logObstacle.bin");
	MyShape[RIVER] = new Shape("resources/image/river_lane.bin");
	MyShape[RED_LIGHT] = new Shape("resources/image/red_light.bin");
	MyShape[GREEN_LIGHT] = new Shape("resources/image/green_light.bin");
	MyShape[BACKGROUND] = new Shape("resources/image/background.bin");
	MyShape[LOAD_GAME_BUTTON] = new Shape("resources/image/loadgame.bin");
	MyShape[LOAD_GAME_BUTTON_HOVER] = new Shape("resources/image/loadgame-2.bin");
	MyShape[NEW_GAME_BUTTON] = new Shape("resources/image/newgame.bin");
	MyShape[NEW_GAME_BUTTON_HOVER] = new Shape("resources/image/newgame-2.bin");
	MyShape[RANK_BUTTON] = new Shape("resources/image/rank.bin");
	MyShape[RANK_BUTTON_HOVER] = new Shape("resources/image/rank-2.bin");
	MyShape[SETTING_BUTTON] = new Shape("resources/image/setting.bin");
	MyShape[SCORE] = new Shape("resources/image/score.bin");
}
