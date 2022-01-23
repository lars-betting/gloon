#pragma once

#include "Command.h"

class WalkDownCommand : public Command
{
public:
	virtual void execute(Character& character) override
	{
		character.walkDown();
	}
};

