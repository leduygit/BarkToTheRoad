#include "Gameplay.h"

Gameplay::Gameplay() : command(nullptr), fact(), m(&fact)
{
	m.addLane();
    Shape* moving = DogMovingShapes[0];
	Shape* staying = DogStayingShapes[0];
	character = new Character{ {90, 0}, staying, moving, 3 };
    m.addLane();
}

void Gameplay::gameLogic()
{
    m.updateOffset(m_speed);
    character->updateOffset(m_speed);

    
    if (character->update())
        m.update();
    

    m.addObstacle();
    m.moveObstacle(*character);
    m.removeObstacle();

    m.render();
    character->render();

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
        saveGame();
        int rand = randomInt(1, 13);
        character->setPos({ static_cast<short>(90 * rand), 0 });
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

void Gameplay::saveGame() const
{
    std::ofstream out("game_save/save.txt");
	out << m << std::endl;
    out << *character << std::endl;
    out << m_score << std::endl;
    out << m_speed << std::endl;
	out.close();
}

void Gameplay::loadGame()
{
    std::ifstream in("game_save/save.txt");
	in >> m;
    Character temp;
    in >> temp;
    character = new Character(temp);
	in >> m_score;
	in >> m_speed;
	in.close();
}

Gameplay::~Gameplay()
{
    //delete character;
}

