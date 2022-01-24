#pragma once

#include "InputHandler.h"
#include "Character.h"
#include "SFML\Graphics.hpp"
#include "SFML\System.hpp"



class GameManager
{
public:
	GameManager();
	~GameManager();

public:
	void init();
	void update();
	void render(sf::RenderWindow& window);

private:
	float moveSpeed;
	
	Character* gloon;
	InputHandler inputHandler;

	sf::Clock Clock;
};

