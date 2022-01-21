
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <iostream>

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
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}