#ifndef WORLD_H
#define WORLD_H

#include "World.h"
#include "Character.h"
#include <SFML\Window\Keyboard.hpp>
#include <SFML\Graphics\Text.hpp>
#include <SFML\Graphics\Font.hpp>
#include <SFML\System\Time.hpp>
#include <SFML\Graphics\RenderWindow.hpp>



class GameManager : private sf::NonCopyable
{
public:
	GameManager();
	void run();

public:
	void processEvents();
	void update(sf::Time elapsedTime);
	void render();

	void updateStatistics(sf::Time elapsedTime);
	void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

private:
	static const sf::Time TimePerFrame;
	
	sf::RenderWindow mWindow;
	World mWorld;

	sf::Font mFont;
	sf::Text mStatisticsText;
	sf::Time mStatisticsUpdateTime;
	std::size_t mStatisticsNumFrames;
	
};
#endif

