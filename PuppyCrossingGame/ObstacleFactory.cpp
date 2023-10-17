#include "ObstacleFactory.h"

int randomInt(int l, int r)
{
	srand(time(NULL));
	int x = l + rand() % (r - l + 1);
	return x;
}

