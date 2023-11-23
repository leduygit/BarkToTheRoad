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
	m.addLane();
    Shape* moving = DogMovingShapes[0];
	Shape* staying = DogStayingShapes[0];
	character = new Character{ {90, 0}, staying, moving, 3 };
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

    if (m.checkCollision(*character)) {
        int rand = randomInt(1, 13);
        character->setPos({ static_cast<short>(90 * rand), 0 });
        //saveGame();
    }
}

bool Gameplay::isStart()
{
    return haveStarted;
}

bool Gameplay::isEnd()
{
    if (character->getPos().Y <= -90 || m.checkCollision(*character))
		return true;
    return false;
}

int Gameplay::getScore() const
{
    return m_score;
}

bool Gameplay::getIsNewGame() const
{
    return m_is_new_game;
}

void Gameplay::saveGame() const
{
    std::ofstream out("game_save/save.txt");
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
    //Character temp;
    //in >> temp;
    //character = new Character(temp);
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

Gameplay::~Gameplay()
{
    //delete character;
}

void Gameplay::render()
{
    m.render();
    character->render();
}

void Gameplay::newGame()
{
    loadGame("save.txt");
}

