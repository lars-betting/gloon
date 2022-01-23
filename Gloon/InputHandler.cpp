#include "InputHandler.h"
#include <iostream>


InputHandler::InputHandler()
{
	W_KEY = new WalkUpCommand;
	A_KEY = new WalkLeftCommand;
	S_KEY = new WalkDownCommand;
	D_KEY = new WalkRightCommand;
}

InputHandler::~InputHandler()
{
	delete W_KEY;
	delete A_KEY;
	delete S_KEY;
	delete D_KEY;
}

Command* InputHandler::handleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		std::cout << "W key is pressed" << std::endl;
		return W_KEY;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		std::cout << " A key is pressed" << std::endl;
		return A_KEY;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		std::cout << "S key is pressed" << std::endl;
		return S_KEY;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		std::cout << "D key is pressed" << std::endl;
		return D_KEY;
	}

	return NULL;
	
}


