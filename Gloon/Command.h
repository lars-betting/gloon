#pragma once

//this command class principle is used with help from https://gameprogrammingpatterns.com/command.html
#include "Character.h"

class Command
{
public:
	
	virtual void execute(Character& character) = 0;

};

