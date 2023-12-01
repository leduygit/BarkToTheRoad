#include "Lane.h"

constexpr int NUM_SQUARE = 14;


Lane::~Lane()
{
	for (auto obs : m_obs)
	{
		delete obs;
	}
	m_obs.clear();
}

Lane& Lane::operator=(const Lane& lane)
{
	m_position = lane.m_position;
	for (auto obs : lane.m_obs)
	{
		m_obs.push_back(new Obstacle(*obs));
	}
	m_light = lane.m_light;
	direction = lane.direction;
	m_shapeIndex = lane.m_shapeIndex;
	m_factoryIndex = lane.m_factoryIndex;
	switch (m_factoryIndex)
	{
	case AsphaltFactory:
		m_fact = new AsphaltObstacleFactory();
		break;
	case GrassFactory:
		m_fact = new GrassObstacleFactory();
		break;
	case RiverFactory:
		m_fact = new RiverObstacleFactory();
		break;
	case RailFactory:
		m_fact = new RailObstacleFactory();
		break;
	default:
		break;
	}
	m_shape = lane.m_shape;
	return *this;
}

Lane::Lane(const COORD& pos) :
	m_position{ pos }
{
	m_shape = *MyShape[ROAD];
	if (randomInt(0, 100) % 2)
		m_light.setPos({ 300, m_position.Y });
	else
		m_light.setPos({ 811, m_position.Y });
	m_light.setGreenDuration(randomInt(1000, 8000));
	m_light.setRedDuration(5000);
	if (randomInt(0, 100) % 2)
		direction *= -1;
}

Lane::Lane(const Lane& lane)
{
	m_position = lane.m_position;
	for (auto obs : lane.m_obs)
	{
		m_obs.push_back(new Obstacle(*obs));
	}
	m_light = lane.m_light;
	direction = lane.direction;
	m_shapeIndex = lane.m_shapeIndex;
	m_factoryIndex = lane.m_factoryIndex;
	m_fact = lane.m_fact;
	m_shape = lane.m_shape;
}

void Lane::render(int offset)
{
	int x = 0;
	for (int i = 0; i < NUM_SQUARE; i++) {
		m_shape.render(x, m_position.Y - offset);
		x += 90;
	}

	for (auto obs : m_obs) {
		obs->render(offset);
	}

	if (isRiverLane() == false) m_light.render(offset);
}

bool Lane::spawnRate()
{
	int x = randomInt(0, 1000);
	if (x < 600) return false;
	return true;
}

void Lane::addObstacle()
{
	int x = randomInt(0, 1000);
	if (spawnRate() == false) return;
	if (m_obs.size() >= 5) return;
	Obstacle* newObstacle = nullptr;
	if (direction > 0)
	{
		newObstacle = m_fact->createObstacle(m_position);
	}
	else {
		newObstacle = m_fact->createObstacle({ static_cast<short>(m_position.X + 1280), m_position.Y });
	}
	if (newObstacle == nullptr) return;
	if (m_obs.size() == 0 || newObstacle->isCollison(*m_obs.back()) == false)
		m_obs.push_back(newObstacle);
	else
		delete newObstacle;
}

void Lane::removeObstacle()
{
	int sz = m_obs.size();
	for (int i = sz - 1; i >= 0; --i)
	{
		COORD pos = m_obs[i]->getPos();
		if ((direction > 0 && isOutSideRight(pos)) || (direction < 0 && isOutSideLeft(pos)))
		{
			std::swap(m_obs.back(), m_obs[i]);
			if (m_obs.back()) {
				delete m_obs.back();
				m_obs.pop_back();
			}
		}
		else break;
	}
}

void Lane::moveObstacle()
{
	m_light.update();

	bool isRed = m_light.isRed();

	for (int i = 0; i < m_obs.size(); ++i)
	{
		Obstacle* obs = m_obs[i];
		COORD pos = obs->getPos();
		SHORT x = 50 * direction;
		COORD lightPos = m_light.getPos();
		if (isRed == false) obs->move({ static_cast<short>(pos.X + x), pos.Y });
		else {
			if (direction > 0) {
				// if go pass the light
				if (pos.X > lightPos.X + 10) {
					obs->move({ static_cast<short>(pos.X + x), pos.Y });
				}
			}
			else
			{
				if (pos.X < lightPos.X - 10) {
					obs->move({ static_cast<short>(pos.X + x), pos.Y });
				}
			}

			if (direction > 0) { // left -> right
				// if behind the light
				if (pos.X <= lightPos.X - 90) {
					if (pos.X + x <= lightPos.X - 90)
						obs->move({ static_cast<short>(pos.X + x), pos.Y });
					else
						obs->stopMoving();
				}
			}
			else {
				if (pos.X >= lightPos.X + 90) {
					if (pos.X + x >= lightPos.X + 90)
						obs->move({ static_cast<short>(pos.X + x), pos.Y });
					else
						obs->stopMoving();
				}
			}
		}
		if (i > 0)
		{
			auto preObs = m_obs[i - 1];
			COORD curPos = preObs->getPos();
			COORD newPos = { curPos.X - 20 * direction, curPos.Y };
			preObs->setPos(newPos);
			if (preObs->isCollison(*obs)) obs->stopMoving();
			preObs->setPos(curPos);
		}
	}
}


bool Lane::checkCollision(Character& e)
{
	for (auto obstacle : m_obs)
	{
		if (obstacle->isCollison(e))
			return true;
	}
	return false;
}

void Lane::setPos(const COORD& pos)
{
	m_position = pos;
	for (auto obs : m_obs)
	{
		COORD obsPos = obs->getPos();
		obs->setPos({ obsPos.X, pos.Y });
	}

	COORD lightPos = m_light.getPos();
	m_light.setPos({ lightPos.X, pos.Y });
}

COORD Lane::getCollision(Character& c)
{
	for (auto obstacle : m_obs)
	{
		if (obstacle->isCollison(c))
			return obstacle->getPos();
	}
	return { -1, -1 };
}

void Lane::reverseDirection()
{
	direction *= -1;
}

void Lane::setFactoryIndex(int index)
{
	m_factoryIndex = index;
}

int Lane::getFactoryIndex() const
{
	return m_factoryIndex;
}

std::istream& operator>>(std::istream& in, Lane& lane)
{
	in >> lane.m_position.X >> lane.m_position.Y;
	int m_size;
	in >> m_size;
	for (int i = 0; i < m_size; ++i)
	{
		Obstacle* temp = nullptr;
		int x, y, obstacleShapeIndex, isStanding, speed;
		in >> x >> y >> obstacleShapeIndex >> isStanding >> speed;
		switch (obstacleShapeIndex)
		{
		case CAR_RIGHT:
			temp = new CarObstacle({ static_cast<short>(x), static_cast<short>(y) });
			break;
		case CAR_LEFT:
			temp = new CarObstacle({ static_cast<short>(x), static_cast<short>(y) }, 1);
			break;
		case BUS_RIGHT:
			temp = new BusObstacle({ static_cast<short>(x), static_cast<short>(y) });
			break;
		case BUS_LEFT:
			temp = new BusObstacle({ static_cast<short>(x), static_cast<short>(y) }, 1);
			break;
		case GRASS_0:
		case GRASS_1:
		case GRASS_2:
		case GRASS_3:
		case GRASS_4:
		case STONE:
		case STONE_1:
		case BUSH_2:
			temp = new GrassObstacle({ static_cast<short>(x), static_cast<short>(y) }, obstacleShapeIndex);
			break;
		case TRAIN_RIGHT:
			temp = new TrainObstacle({ static_cast<short>(x), static_cast<short>(y) });
			break;
		case TRAIN_LEFT:
			temp = new TrainObstacle({ static_cast<short>(x), static_cast<short>(y) }, 1);
			break;
		case LOG:
			temp = new RaftObstacle({ static_cast<short>(x), static_cast<short>(y) });
			break;
		default:
			temp = new CarObstacle({ static_cast<short>(x), static_cast<short>(y) });
			break;
		}
		lane.m_obs.push_back(temp);
	}

	in >> lane.m_light;

	in >> lane.direction;

	in >> lane.m_shapeIndex;

	switch (lane.m_factoryIndex)
	{
	case AsphaltFactory:
		lane.m_fact = new AsphaltObstacleFactory();
		break;
	case GrassFactory:
		lane.m_fact = new GrassObstacleFactory();
		break;
	case RiverFactory:
		lane.m_fact = new RiverObstacleFactory();
		break;
	case RailFactory:
		lane.m_fact = new RailObstacleFactory();
		break;
	default:
		break;
	}

	lane.m_shape = *MyShape[lane.m_shapeIndex];


	return in;
}

std::ostream& operator<<(std::ostream& out, const Lane& lane)
{
	out << lane.m_position.X << " " << lane.m_position.Y << "\n";
	out << lane.m_obs.size() << "\n";
	for (auto obs : lane.m_obs)
	{
		out << *obs << '\n';
	}
	out << lane.m_light << "\n";
	out << lane.direction << " ";
	out << lane.m_shapeIndex << " ";
	return out;
}
