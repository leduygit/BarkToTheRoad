#include "Gameplay.h"

Gameplay::Gameplay() : command(nullptr), fact(), m(&fact)
{
	m.addLane();
	Shape* moving = new Shape[3]{ *MyShape[DOG_STAY_1], *MyShape[DOG_JUMP_1], *MyShape[DOG_JUMP_2] };
	Shape* staying = new Shape[2]{ *MyShape[DOG_STAY_1], *MyShape[DOG_STAY_2] };
	character = new Character{ {1170, 90}, staying, moving, 3 };
    m.addLane();
}

void Gameplay::gameLogic()
{
    m.addObstacle();
    m.moveObstacle(*character);
    m.removeObstacle();

    m.render();
    character->render();

    if (command != nullptr) {
        if (command->isValidMove(*character, m)) {
            command->execute(*character, m);
        }
        command = nullptr;
    }

    if (m.checkCollision(*character)) {
        int rand = randomInt(1, 13);
        character->setPos({ static_cast<short>(90 * rand), 0 });
    }
}

Gameplay::~Gameplay()
{
    //delete character;
}

