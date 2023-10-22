#include "MoveUpCommand.h"

void MoveUpCommand::execute(Character& c)
{
	c.move({ 100, 500 });
}
