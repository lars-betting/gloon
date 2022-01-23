#pragma once

#include "Command.h"
#include "WalkDownCommand.h"
#include "WalkLeftCommand.h"
#include "WalkRightCommand.h"
#include "WalkUpCommand.h"

class InputHandler
{
public:
	InputHandler();
	~InputHandler();
	Command* handleInput();
	
private:
	Command* W_KEY;
	Command* A_KEY;
	Command* S_KEY;
	Command* D_KEY;

};

