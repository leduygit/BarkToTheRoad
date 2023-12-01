#include "Obstacle.h"

Obstacle::Obstacle(const COORD& pos, int shapeType, int isStanding, int speed)
{
	m_position = pos;
	m_shape = MyShape[shapeType];
	m_shapeIndex = shapeType;
	m_type = (ObstacleType)isStanding;
	setRate(speed);
}

std::istream& operator>>(std::istream& in, Obstacle& obs)
{
	int x, y, shapeIndex, isStanding, speed;
	in >> x >> y >> shapeIndex >> isStanding >> speed;
	COORD pos = { (short)x, (short)y };
	obs = Obstacle(pos, shapeIndex, isStanding, speed);
	return in;
}

std::ostream& operator<<(std::ostream& out, const Obstacle& obs)
{
	out << obs.m_position.X << " " << obs.m_position.Y << " " << obs.m_shapeIndex << " " << obs.m_type << " " << obs.m_rate;
	return out;
}

BusObstacle::BusObstacle(const COORD &pos)
{
	m_shape = MyShape[BUS_RIGHT];
	m_position = pos;
	m_shapeIndex = BUS_RIGHT;
	setRate(Global::MEDIUM_SPEED);
}

BusObstacle::BusObstacle(const COORD& pos, bool flag)
{
	m_shape = MyShape[BUS_LEFT];
	m_position = pos;
	m_shapeIndex = BUS_LEFT;
	setRate(Global::MEDIUM_SPEED);
}

CarObstacle::CarObstacle(const COORD &pos)
{
	int x = rand();
	if (x % 4 == 0)
	{
		m_shape = MyShape[CAR_WHITE_RIGHT];
		m_shapeIndex = CAR_WHITE_RIGHT;
	}
	else if (x % 4 == 1) {
		m_shape = MyShape[G63_RIGHT];
		m_shapeIndex = G63_RIGHT;
	} else if (x % 4 == 2) {
		m_shape = MyShape[CAR_YELLOW_RIGHT];
		m_shapeIndex = CAR_YELLOW_RIGHT;
	}
	else if (x % 4 == 3) {
		m_shape = MyShape[G63_BLACK_RIGHT];
		m_shapeIndex = G63_BLACK_RIGHT;
	}
	m_position = pos;
	setRate(Global::HIGH_SPEED);
}

CarObstacle::CarObstacle(const COORD& pos, bool flag)
{
	int x = rand();
	if (x % 4 == 0)
	{
		m_shape = MyShape[CAR_WHITE_LEFT];
		m_shapeIndex = CAR_WHITE_LEFT;
	}
	else if (x % 4 == 1) {
		m_shape = MyShape[G63_LEFT];
		m_shapeIndex = G63_LEFT;
	}
	else if (x % 4 == 2) {
		m_shape = MyShape[CAR_YELLOW_LEFT];
		m_shapeIndex = CAR_YELLOW_LEFT;
	}
	else if (x % 4 == 3) {
		m_shape = MyShape[G63_BLACK_LEFT];
		m_shapeIndex = G63_BLACK_LEFT;
	}
	m_position = pos;
	setRate(Global::HIGH_SPEED);
}

GrassObstacle::GrassObstacle(const COORD &pos)
{
	int random = rand() % 3;
	if (random == 1) {
		m_shape = MyShape[STONE];
		m_shapeIndex = STONE;
	}
	else if (random == 2) {
		m_shape = MyShape[STONE_1];
		m_shapeIndex = STONE_1;
	}
	else {
		m_shape = MyShape[BUSH_2];
		m_shapeIndex = BUSH_2;
	}
	m_position = pos;
	m_type = STANDING;
}

GrassObstacle::GrassObstacle(const COORD& pos, int index)
{
	m_shape = MyShape[index];
	m_shapeIndex = index;
	m_position = pos;
	m_type = STANDING;
}

TrainObstacle::TrainObstacle(const COORD &pos)
{
	m_shape = MyShape[TRAIN_RIGHT];
	m_position = pos;
	m_shapeIndex = TRAIN_RIGHT;
	setRate(Global::VERY_HIGH_SPEED);
}

TrainObstacle::TrainObstacle(const COORD& pos, bool flag)
{
	m_shape = MyShape[TRAIN_LEFT];
	m_position = pos;
	m_shapeIndex = TRAIN_LEFT;
	setRate(Global::VERY_HIGH_SPEED);
}

RaftObstacle::RaftObstacle(const COORD &pos)
{
	m_shape = MyShape[LOG];
	m_shapeIndex = LOG;
	m_position = pos;
}