#pragma once

#include "Command.h"
class WalkRightCommand : public Command
{
public:
	virtual void execute(Character& character) override
	{
		character.walkRight();
	}
};

