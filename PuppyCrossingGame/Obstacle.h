#pragma once
#include "Entity.h"
class Obstacle : public Entity
{
private:
	int a = 5;
protected:
	enum ObstacleType {
		MOVING, STANDING
	};
	ObstacleType m_type{MOVING};
public:

	COORD getPos()
	{
		return m_position;
	}
	using Entity::setRate;
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
	CarObstacle(const COORD& pos, bool flag);
};

class GrassObstacle : public Obstacle
{
public:
	GrassObstacle() = default;
	GrassObstacle(const COORD &pos);
	//bool checkCollision(const Entity& otherEntity) const override;
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


