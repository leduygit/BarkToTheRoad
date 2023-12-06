#include "LoadShape.h"

std::vector<Shape*> MyShape(100);
std::vector<Shape*> DogMovingShapes(10);
std::vector<Shape*> DogStayingShapes(10);
std::vector<Shape*> DogDyingShapes(10);

void initShape() {
	MyShape[CAR_RIGHT] = new Shape{ "resources/image/car_right.bin" };
	MyShape[CAR_LEFT] = new Shape{ "resources/image/car_left.bin" };
	MyShape[CAR_WHITE_RIGHT] = new Shape{ "resources/image/car_white_right.bin" };
	MyShape[CAR_WHITE_LEFT] = new Shape{ "resources/image/car_white_left.bin" };
	MyShape[G63_RIGHT] = new Shape{ "resources/image/g63_right.bin" };
	MyShape[G63_LEFT] = new Shape{ "resources/image/g63_left.bin" };
	MyShape[CAR_YELLOW_RIGHT] = new Shape{ "resources/image/car_yellow_right.bin" };
	MyShape[CAR_YELLOW_LEFT] = new Shape{ "resources/image/car_yellow_left.bin" };
	MyShape[G63_BLACK_RIGHT] = new Shape{ "resources/image/g63_black_right.bin" };
	MyShape[G63_BLACK_LEFT] = new Shape{ "resources/image/g63_black_left.bin" };
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
	MyShape[TRAIN_LEFT] = new Shape("resources/image/train_left.bin");
	MyShape[BUS_RIGHT] = new Shape("resources/image/bus_right.bin");
	MyShape[BUS_LEFT] = new Shape("resources/image/bus_left.bin");
	MyShape[DOG_STAY_1] = new Shape("resources/image/sit-1.bin");
	MyShape[DOG_STAY_2] = new Shape("resources/image/sit-2.bin");
	MyShape[DOG_JUMP_1] = new Shape("resources/image/jump-1.bin");
	MyShape[DOG_JUMP_2] = new Shape("resources/image/jump-2.bin");
	MyShape[DOG_JUMP_3] = new Shape("resources/image/jump-3.bin");
	MyShape[DOG_STAY_1_LEFT] = new Shape("resources/image/sit-1_left.bin");
	MyShape[DOG_STAY_2_LEFT] = new Shape("resources/image/sit-2_left.bin");
	MyShape[DOG_JUMP_1_LEFT] = new Shape("resources/image/jump-1_left.bin");
	MyShape[DOG_JUMP_2_LEFT] = new Shape("resources/image/jump-2_left.bin");
	MyShape[DOG_JUMP_3_LEFT] = new Shape("resources/image/jump-3_left.bin");
	MyShape[DOG_DIE] = new Shape("resources/image/dog_die.bin");
	MyShape[RAIL] = new Shape("resources/image/railway.bin");
	//MyShape[LOG] = new Shape("resources/image/logObstacle.bin"); // 149x90
	MyShape[LOG] = new Shape("resources/image/test_log.bin"); // 90x90
	MyShape[RIVER] = new Shape("resources/image/river_lane.bin");
	MyShape[RED_LIGHT] = new Shape("resources/image/red_light.bin");
	MyShape[GREEN_LIGHT] = new Shape("resources/image/green_light.bin");
	MyShape[BACKGROUND] = new Shape("resources/image/background.bin");
	MyShape[BACKGROUND_EMPTY] = new Shape("resources/image/background-empty.bin");
	MyShape[LOAD_GAME_BUTTON] = new Shape("resources/image/loadgame.bin");
	MyShape[LOAD_GAME_BUTTON_HOVER] = new Shape("resources/image/loadgame-2.bin");
	MyShape[NEW_GAME_BUTTON] = new Shape("resources/image/newgame.bin");
	MyShape[NEW_GAME_BUTTON_HOVER] = new Shape("resources/image/newgame-2.bin");
	MyShape[RANK_BUTTON] = new Shape("resources/image/trophy.bin");
	MyShape[RANK_BUTTON_HOVER] = new Shape("resources/image/trophy_hover.bin");
	MyShape[SETTING_BUTTON] = new Shape("resources/image/setting.bin");
	MyShape[SCORE] = new Shape("resources/image/score.bin");
	MyShape[QUIT_BUTTON] = new Shape("resources/image/quit.bin");
	MyShape[QUIT_BUTTON_HOVER] = new Shape("resources/image/quit-2.bin");
	MyShape[PAUSE] = new Shape("resources/image/pause.bin");
	MyShape[PAUSE_HOVER] = new Shape("resources/image/pause_hover.bin");
	MyShape[SAVE_GAME_BUTTON] = new Shape("resources/image/savegame-2.bin");
	MyShape[SAVE_GAME_BUTTON_HOVER] = new Shape("resources/image/savegame.bin");
	MyShape[SETTING_BUTTON] = new Shape("resources/image/setting.bin");
	MyShape[SETTING_BUTTON_HOVER] = new Shape("resources/image/setting_hover.bin");
	MyShape[HOME] = new Shape("resources/image/home.bin");
	MyShape[HOME_HOVER] = new Shape("resources/image/home-2.bin");
	MyShape[PAUSE_WINDOW] = new Shape("resources/image/pause-window.bin");
	MyShape[RESUME_BUTTON] = new Shape("resources/image/resume.bin");
	MyShape[RESUME_BUTTON_HOVER] = new Shape("resources/image/resume-2.bin");
	MyShape[CLOSE_DIALOG] = new Shape("resources/image/close.bin");
	MyShape[GHOST] = new Shape("resources/image/ghost.bin");
	MyShape[GAME_OVER] = new Shape("resources/image/gameover.bin");
	MyShape[TROPHY_SMALL] = new Shape("resources/image/trophy-2.bin");
	MyShape[TROPHY_SMALL_HOVER] = new Shape("resources/image/trophy_small_hover.bin");
	MyShape[TEXTBOX] = new Shape("resources/image/textbox.bin");
	MyShape[LEADERBOARD] = new Shape("resources/image/rank-window.bin");
	MyShape[AMBULANCE] = new Shape("resources/image/ambulance.bin");
	MyShape[SETTING_WINDOW] = new Shape("resources/image/setting-window.bin");
	MyShape[SPEAKER] = new Shape("resources/image/speaker.bin");
	MyShape[SPEAKER_HOVER] = new Shape("resources/image/speaker_hover.bin");
	MyShape[MUTE] = new Shape("resources/image/mute.bin");
	MyShape[MUTE_HOVER] = new Shape("resources/image/mute_hover.bin");
	MyShape[CREDIT_BUTTON] = new Shape("resources/image/credit.bin");
	MyShape[CREDIT_BUTTON_HOVER] = new Shape("resources/image/credit_hover.bin");
	MyShape[CREDIT_WINDOW] = new Shape("resources/image/credit-window.bin");
	MyShape[INSTRUCTION_WINDOW_1] = new Shape("resources/image/instruction_1.bin");
	MyShape[INSTRUCTION_WINDOW_2] = new Shape("resources/image/instruction_2.bin");
	MyShape[NEXT_BUTTON] = new Shape("resources/image/next_button.bin");
	MyShape[NEXT_BUTTON_HOVER] = new Shape("resources/image/next_button_hover.bin");
	MyShape[PRE_BUTTON] = new Shape("resources/image/pre_button.bin");
	MyShape[PRE_BUTTON_HOVER] = new Shape("resources/image/pre_button_hover.bin");
	DogMovingShapes[0] = new Shape[3]{ *MyShape[DOG_JUMP_1], *MyShape[DOG_JUMP_2], *MyShape[DOG_JUMP_3] };
	DogStayingShapes[0] = new Shape[2]{ *MyShape[DOG_STAY_1], *MyShape[DOG_STAY_2] };
	DogMovingShapes[1] = new Shape[3]{ *MyShape[DOG_JUMP_1_LEFT], *MyShape[DOG_JUMP_2_LEFT], *MyShape[DOG_JUMP_3_LEFT] };
	DogStayingShapes[1] = new Shape[2]{ *MyShape[DOG_STAY_1_LEFT], *MyShape[DOG_STAY_2_LEFT] };
	DogDyingShapes[0] = new Shape[2]{ *MyShape[DOG_DIE], *MyShape[DOG_DIE] };
}

void deleteShape()
{
	for (int i = 0; i < MyShape.size(); i++)
	{
		if (MyShape[i] != nullptr)
			delete MyShape[i];
	}
	for (int i = 0; i < DogMovingShapes.size(); i++)
	{
		if (DogMovingShapes[i] != nullptr)
			delete[] DogMovingShapes[i];
	}
	for (int i = 0; i < DogStayingShapes.size(); i++)
	{
		if (DogStayingShapes[i] != nullptr)
			delete[] DogStayingShapes[i];
	}
	for (int i = 0; i < DogDyingShapes.size(); i++)
	{
		if (DogDyingShapes[i] != nullptr)
			delete[] DogDyingShapes[i];
	}
}
