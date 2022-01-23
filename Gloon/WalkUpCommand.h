#pragma once

#include "Command.h"
class WalkUpCommand : public Command
{
public:
	virtual void execute(Character& character) override
	{
		character.walkUp();
	}
};

