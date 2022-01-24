#include "GameManager.h"

GameManager::GameManager()
{
}

GameManager::~GameManager()
{
}

void GameManager::init()
{
	gloon = new Character;
}

void GameManager::update()
{
	float elapsedTime = Clock.getElapsedTime().asMilliseconds();
	Clock.restart();

	gloon->handleWalking(moveSpeed * elapsedTime);
	
}

void GameManager::render(sf::RenderWindow& window)
{
	
	gloon->draw(&window);
}
