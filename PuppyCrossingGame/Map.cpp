#include "Map.h"
#define NUM_LANE 8


Map::~Map()
{
	for (int i = 0; i < MAX_LANE; ++i)
		delete m_lane[i];
	delete m_fact;
}

Map::Map(LaneFactory* fact)
{
	m_fact = fact;
	addLane();
}

Map& Map::operator=(const Map& m)
{
	// TODO: insert return statement here
	for (int i = 0; i < MAX_LANE; ++i)
	{
		int type = m.m_lane[i]->getFactoryIndex();
		switch (type)
		{
		case AsphaltFactory:
			m_lane[i] = new AsphaltLane();
			break;
		case GrassFactory:
			m_lane[i] = new GrassLane();
			break;
		case RiverFactory:
			m_lane[i] = new RiverLane();
			break;
		case RailFactory:
			m_lane[i] = new RailLane();
			break;
		default:
			m_lane[i] = new GrassLane();
			break;
		}
		*m_lane[i] = *m.m_lane[i];
	}

	m_offset = m.m_offset;
	m_factoryType = m.m_factoryType;
	switch (m_factoryType)
	{
	case SUMMER:
		m_fact = new SummerLaneFactory();
		break;
	case SPRING:
		m_fact = new SpringLaneFactory();
		break;
	case WINTER:
		//m_fact = new WinterLaneFactory();
		break;
	case AUTUMN:
		//m_fact = new AutumnLaneFactory();
		break;
	default:
		break;
	}

	return *this;
}

bool Map::checkCollision(Character& e)
{
	if (e.isStanding() == false) return false;
	COORD pos = e.getPos();
	int i = pos.Y / 90;
	if (i >= m_lane_number || i < 0) return false;
	if (m_lane[i]->checkCollision(e)) return true;
	return false;
}

bool Map::checkCollisionWithStaticObstacle(Character& e)
{
	if (e.getPos().X < 0 || e.getPos().X >= 1260 || e.getPos().Y < 0) return true;
	COORD pos = e.getPos();
	int i = pos.Y / 90;
	if (i >= m_lane_number || i < 0) return false;
	if (m_lane[i]->checkCollision(e) && !m_lane[i]->isStaticLane()) return true;
	return false;
}

void Map::moveObstacle(Character& c)
{
	for (int i = 0; i < m_lane_number; ++i) {
		if (i >= 10) continue;
		m_lane[i]->moveObstacle();
		m_lane[i]->moveObstacle(c);
	}
}

void Map::addObstacle()
{
	//if (randomInt(0, 100) <= 50) return;
	int id = randomInt(0, 100);
	id %= m_lane_number;
	m_lane[id]->addObstacle();
	for (int i = 0; i < m_lane_number; ++i) {
		if ( randomInt(0, 100) <= 30 && m_lane[i]->isRiverLane())
		{
			m_lane[i]->addObstacle();
		}
	}
}

void Map::removeObstacle()
{
	for (int i = 0; i < m_lane_number; ++i)
		m_lane[i]->removeObstacle();
}

void Map::update()
{
	delete m_lane[0];
	for (int i = 0; i < MAX_LANE - 1; ++i)
	{
		m_lane[i] = m_lane[i + 1];
		m_lane[i]->setPos({ 0, static_cast<short>(90 * i) });
	}
	m_lane.pop_back();
	m_lane.push_back(m_fact->createLane({ 0 , static_cast<short>(90 * (MAX_LANE - 1)) }));
	m_offset -= 90;
}

void Map::updateOffset(const int &speed)
{
	m_offset += speed;
}

bool Map::isRiverLane(COORD pos)
{
	int i = pos.Y / 90;
	if (i >= m_lane_number || i < 0) return false;
	return m_lane[i]->isRiverLane();
}

void Map::render()
{
	for (int i = 0; i < m_lane_number; ++i)
		if (i < 11) m_lane[i]->render(m_offset);
}

void Map::addLane()
{
	for (int i = 0; i < 3; ++i)
	{
		m_lane[i] = new GrassLane({ 0, static_cast<short>(90 * i) });
	}
	for (short i = 3; i < MAX_LANE; ++i)
	{
		m_lane[i] = m_fact->createLane({ 0 , static_cast<short>(90 * i) });
	}
	return;
}

std::istream& operator>>(std::istream& in, Map& m)
{
	m.m_lane.clear();
	for (int i = 0; i < MAX_LANE; ++i)
	{
		int factoryIndex;
		in >> factoryIndex;
		Lane* lane;
		switch (factoryIndex)
		{
		case AsphaltFactory:
			lane = new AsphaltLane();
			break;
		case GrassFactory:
			lane = new GrassLane();
			break;
		case RiverFactory:
			lane = new RiverLane();
			break;
		case RailFactory:
			lane = new RailLane();
			break;
		default:
			lane = new GrassLane();
			break;
		}
		lane->setFactoryIndex(factoryIndex);
		in >> *lane;
		m.m_lane.push_back(lane);
	}
	in >> m.m_offset;
	in >> m.m_factoryType;

	switch (m.m_factoryType)
	{
	case SUMMER:
		m.m_fact = new SummerLaneFactory();
		break;
	case SPRING:
		m.m_fact = new SpringLaneFactory();
		break;
	case WINTER:
		//m.m_fact = new WinterLaneFactory();
		break;
	case AUTUMN:
		//m.m_fact = new AutumnLaneFactory();
		break;
	default:
		break;
	}
	return in;
}

std::ostream& operator<<(std::ostream& out, const Map& m)
{
	for (int i = 0; i < MAX_LANE; ++i)
	{
		out << m.m_lane[i]->getFactoryIndex() << std::endl;
		out << *m.m_lane[i] << std::endl;
		out << std::endl;
	}
	out << m.m_offset << std::endl;
	out << m.m_factoryType << std::endl;
	return out;
}

