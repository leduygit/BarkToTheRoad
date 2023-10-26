#pragma once
#include "Entity.h"
class Obstacle : public Entity
{
private:
	int a = 5;
public:
	void render() {
		Entity::render();
	}

	COORD getPos()
	{
		return m_position;
	}
	
};

class BusObstacle : public Obstacle
{
public:
	BusObstacle(COORD pos);

};

class CarObstacle :public Obstacle
{
public:
	CarObstacle(COORD pos = { 0, 0 });
};

class GrassObstacle : public Obstacle
{
public:
	GrassObstacle() = default;
	GrassObstacle(COORD pos);
	//bool checkCollision(const Entity& otherEntity) const override;
private:
};

class TrainObstacle : public Obstacle
{
public:
	TrainObstacle() = default;
	TrainObstacle(COORD pos);
private:
};




