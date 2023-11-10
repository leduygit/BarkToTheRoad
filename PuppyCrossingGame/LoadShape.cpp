#include "LoadShape.h"

std::vector<Shape*> MyShape(100);

void initShape() {
	MyShape[CAR_RIGHT] = new Shape{ "image/car_right.bin" };
	MyShape[GRASS_0] = new Shape("image/grass_0.bin");
	MyShape[GRASS_1] = new Shape("image/grass_1.bin");
	MyShape[GRASS_2] = new Shape("image/grass_2.bin");
	MyShape[GRASS_3] = new Shape("image/grass_3.bin");
	MyShape[GRASS_4] = new Shape("image/grass_4.bin");
	MyShape[STONE] = new Shape("image/stone.bin");
	MyShape[STONE_1] = new Shape("image/stone1.bin");
	MyShape[BUSH_2] = new Shape("image/bush2.bin");
	MyShape[ROAD] = new Shape("image/road.bin");
	MyShape[TRAIN_RIGHT] = new Shape("image/train_right.bin");
	MyShape[DOG_STAY_1] = new Shape("image/dog_stay_1.bin");
	MyShape[DOG_STAY_2] = new Shape("image/dog_stay_2.bin");
	MyShape[DOG_JUMP_1] = new Shape("image/dog_jump_1.bin");
	MyShape[DOG_JUMP_2] = new Shape("image/dog_jump_2.bin");
	MyShape[RAIL] = new Shape("image/railway_lane.bin");
	MyShape[LOG] = new Shape("image/logObstacle.bin");
	MyShape[RIVER] = new Shape("image/river_lane.bin");
	MyShape[RED_LIGHT] = new Shape("image/red_light.bin");
	MyShape[GREEN_LIGHT] = new Shape("image/green_light.bin");
	MyShape[BACKGROUND] = new Shape("image/background.bin");
	MyShape[LOAD_GAME_BUTTON] = new Shape("image/loadgame.bin");
	MyShape[LOAD_GAME_BUTTON_HOVER] = new Shape("image/loadgame-2.bin");
	MyShape[NEW_GAME_BUTTON] = new Shape("image/newgame.bin");
	MyShape[NEW_GAME_BUTTON_HOVER] = new Shape("image/newgame-2.bin");
	MyShape[RANK_BUTTON] = new Shape("image/trophy.bin");
	MyShape[RANK_BUTTON_HOVER] = new Shape("image/trophy.bin");
	MyShape[SETTING_BUTTON] = new Shape("image/setting.bin");
	MyShape[QUIT_BUTTON] = new Shape("image/quit.bin");
	MyShape[QUIT_BUTTON_HOVER] = new Shape("image/quit-2.bin");
}
