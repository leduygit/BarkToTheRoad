#pragma once
#include "Entity.h"

class Obstacle : public Entity
{
private:
protected:
	int m_shapeIndex;
public:
	enum ObstacleType {
		MOVING, STANDING
	};
	ObstacleType m_type{ MOVING };
	Obstacle() = default;
	Obstacle(const COORD &pos, int type, int isStanding, int speed);

	COORD getPos()
	{
		return m_position;
	}
	using Entity::setRate;
	friend std::istream& operator>>(std::istream& in, Obstacle &obs);
	friend std::ostream& operator<<(std::ostream& out, const Obstacle &obs);
};

class BusObstacle : public Obstacle
{
public:
	BusObstacle(const COORD &pos);
	BusObstacle(const COORD& pos, bool flag);
};

class CarObstacle :public Obstacle
{
public:
	CarObstacle(const COORD &pos = { 0, 0 });
	CarObstacle(const COORD& pos, ShapeIndex index);
	CarObstacle(const COORD& pos, bool flag);
};

class GrassObstacle : public Obstacle
{
public:
	GrassObstacle() = default;
	GrassObstacle(const COORD &pos);
	GrassObstacle(const COORD& pos, int index);
private:
};

class TrainObstacle : public Obstacle
{
public:
	TrainObstacle() = default;
	TrainObstacle(const COORD& pos);
	TrainObstacle(const COORD &pos, bool flag);
private:
};

class RaftObstacle : public Obstacle
{
public:
	RaftObstacle() = default;
	RaftObstacle(const COORD &pos);
};


