#pragma once

#include "Command.h"


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

