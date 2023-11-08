#include "LoadShape.h"

std::vector<Shape*> MyShape(100);

void initShape() {
	MyShape[1] = new Shape{ "image/car_right.txt" };
	MyShape[2] = new Shape("image/grass_0.txt");
	MyShape[3] = new Shape("image/grass_1.txt");
	MyShape[4] = new Shape("image/grass_2.txt");
	MyShape[5] = new Shape("image/grass_3.txt");
	MyShape[6] = new Shape("image/grass_4.txt");
	MyShape[7] = new Shape("image/stone.txt");
	MyShape[8] = new Shape("image/stone1.txt");
	MyShape[9] = new Shape("image/bush2.txt");
	MyShape[10] = new Shape("image/road.txt");
	MyShape[11] = new Shape("image/train_right.txt");
	MyShape[12] = new Shape("image/dog_stay_1.txt");
	MyShape[13] = new Shape("image/dog_stay_2.txt");
	MyShape[14] = new Shape("image/dog_jump_1.txt");
	MyShape[15] = new Shape("image/dog_jump_2.txt");
	MyShape[16] = new Shape("image/railway_lane.txt");
	MyShape[17] = new Shape("image/logObstacle.txt");
	MyShape[18] = new Shape("image/river_lane.txt");
	MyShape[19] = new Shape("image/red_light.txt");
	MyShape[20] = new Shape("image/green_light.txt");
  MyShape[21] = new Shape("image/background.txt");
}
