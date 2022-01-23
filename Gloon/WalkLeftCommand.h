#pragma once

#include "Command.h"
class WalkLeftCommand : public Command
{
public:
	virtual void execute(Character& character) override
	{
		character.walkLeft();
	}
};

