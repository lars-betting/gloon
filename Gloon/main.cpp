
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <iostream>
#include "Character.h"
#include "Command.h"
#include "InputHandler.h"

#pragma region
void GetDesktopResolution(int& horizontal, int& vertical)
{
	SetProcessDPIAware();
	RECT desktop;
	const HWND hDesktop = GetDesktopWindow();
	GetWindowRect(hDesktop, &desktop);
	horizontal = desktop.right;
	vertical = desktop.bottom;
}
#pragma endregion Get screen resolution 

int main()
{
	
	int horizontal = 0;
	int vertical = 0;

	GetDesktopResolution(horizontal, vertical);

	// std::cout << horizontal << '\n' << vertical << '\n'; DEBUG

	sf::RenderWindow window(sf::VideoMode((float)horizontal /  1.5f, (float)vertical / 1.5f), "Gloon");
	/*sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);*/
	Character gloon;
	InputHandler inputHandler;
	
	while (window.isOpen())
	{

		sf::Event event;
	
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
					window.close();
					break;
			default:
				    break;
			}
			
		}
		
		window.clear();
		gloon.draw(&window);
		Command* command = inputHandler.handleInput();
		if (command)
		{
			command->execute(gloon);
		}
		
		/*window.draw(shape);*/
		window.display();
	}

	return 0;
}