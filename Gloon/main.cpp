
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <Windows.h>
#include <iostream>
#include "Character.h"
#include "Mirror.h"


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

void update()
{

}

#pragma endregion Get screen resolution 
sf::Clock Clock;
int main()
{
	int horizontal = 0;
	int vertical = 0;

	GetDesktopResolution(horizontal, vertical);

	// std::cout << horizontal << '\n' << vertical << '\n'; DEBUG

	sf::RenderWindow window(sf::VideoMode((float)horizontal /  1.5f, (float)vertical / 1.5f), "Gloon");

#pragma region init variables
	
	//set movement speed (fixed)
	const float moveSpeed = 0.7f;

	//init Mirror
	
	//Init characters
	Character* gloon = new Character;
	Mirror* mirror = new Mirror(*gloon);
#pragma endregion
		
	while (window.isOpen())
	{
#pragma region time
		float elapsedTime = Clock.getElapsedTime().asMilliseconds();
		Clock.restart();
#pragma endregion
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

#pragma region draw calls
		gloon->draw(&window);
		mirror->draw(&window);
#pragma endregion

#pragma region update scene
		gloon->handleWalking(moveSpeed * elapsedTime);
		mirror->moveMirror(*gloon, elapsedTime);
#pragma endregion
		/*window.draw(shape);*/
		window.display();
	}

	return 0;
}