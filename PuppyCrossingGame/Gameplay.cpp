#include "Gameplay.h"

Gameplay::Gameplay() : command(nullptr)
{
    switch (m_fact_type) {
    case SUMMER:
        fact = new SummerLaneFactory{};
        break;
    default:
        break;
    }
    m = Map{ fact };
	//m.addLane();
    Shape* moving = DogMovingShapes[0];
	Shape* staying = DogStayingShapes[0];
	character = new Character{ {630, 0}, staying, moving, 3 };
    while (m.checkCollision(*character))
    {
        character->setPos({ static_cast<short>(randomInt(0,13) * 90), 0 });
    }
    ifstream in("key.txt");
    in >> m_key;
    in.close();
    //m.addLane();
}

void Gameplay::gameLogic()
{

    render();
    if (m_is_paused) return;

    m.updateOffset(m_speed);
    character->updateOffset(m_speed);

    
    if (character->update())
        m.update();
    

    m.addObstacle();
    m.moveObstacle(*character);
    m.removeObstacle();

    if (command != nullptr) {
        if (command->isValidMove(*character, m)) {
            command->execute(*character, m);
            m_speed = 1;
        }
        command = nullptr;
    }

    if (character->getPos().Y > character->getMaxY() && character->isStanding()) {
        m_score++;
        character->setMaxY(character->getPos().Y);
    }

    if (isEnd()) {
        handleEndGame();
    }
}

bool Gameplay::isStart()
{
    return haveStarted;
}

bool Gameplay::isEnd()
{
    if (m_is_paused) return false;
    if (character->getPos().Y <= -90 || m.checkCollision(*character))
		return true;
    return false;
}

int Gameplay::getScore() const
{
    return m_score;
}

void Gameplay::handleEndGame()
{
    exportScore();
    m_is_paused = true;
    Shape* s = new Shape[2]{ *MyShape[GHOST], *MyShape[GHOST] };
    character->setShape(s);
    m_vehicle = new Entity{ COORD{static_cast<short>(character->getPos().X + 600), character->getPos().Y}, MyShape[CAR_LEFT] };
    m_vehicle->move(character->getPos());
    m_ended = true;
}

void Gameplay::exportScore()
{
    std::ofstream out("score.txt", std::ios::app);
    out << encrypt(m_user_name, m_key) << '\n';
    std::string tmp = std::to_string(m_score);
    out << encrypt(tmp, m_key) << '\n';
    out.close();
}

bool Gameplay::getIsNewGame() const
{
    return m_is_new_game;
}

void Gameplay::saveGame(std::string fileName) const
{
    std::ofstream out(fileName);
    if (!out) {
        auto state = out.rdstate();
        return;
    }
	out << m << std::endl;
    out << *character << std::endl;
    out << m_score << std::endl;
    out << m_speed << std::endl;
    out << m_user_name << std::endl;
    out.flush();
	out.close();
}

void Gameplay::loadGame(std::string fileName)
{
    std::ifstream in(fileName, std::ios::in);
	in >> m;
    in >> *character;
	in >> m_score;
	in >> m_speed;
    in >> m_user_name;
	in.close();
    m_is_new_game = false;
    m_is_paused = false;
    m_speed = 0;
}

void Gameplay::setIsNewGame(bool is_new_game)
{
    m_is_new_game = is_new_game;
}

bool Gameplay::getEnded() const
{
    return m_ended;
}

bool Gameplay::vehicleArrived()
{
    return abs(m_vehicle->getPos().X - character->getPos().X) <= 30;
}

Gameplay::~Gameplay()
{
    //delete character;
}

void Gameplay::render()
{
    m.render();
    character->render();
    if (m_ended) {
        m_vehicle->render();
    }
}

void Gameplay::newGame()
{
    loadGame("save.txt");
}

