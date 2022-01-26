#include "GameManager.h"

#include <stdexcept>
#include <iostream>

int main()
{
	try
	{
		GameManager gameManager;
		gameManager.run();
	}
	catch (std::exception& e)
	{
		std::cout << "\nEXCEPTION: " << e.what() << std::endl;
	}
}