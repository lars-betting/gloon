#pragma once

//this command class principle is used with help from https://gameprogrammingpatterns.com/command.html
#include "Character.h"

class Command
{
public:
	~Command();
	virtual void execute(Character& character) = 0;

};

