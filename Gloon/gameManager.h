#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "World.h"
#include "Character.h"
#include "Player.h"
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
	void processInput();
	//void processEvents();
	void update(sf::Time elapsedTime);
	void render();

	void updateStatistics(sf::Time elapsedTime);
	//void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

private:
	static const sf::Time TimePerFrame;
	
	sf::RenderWindow mWindow;
	World mWorld;
	Player mPlayer;

	sf::Font mFont;
	sf::Text mStatisticsText;
	sf::Time mStatisticsUpdateTime;
	std::size_t mStatisticsNumFrames;
	
	
};
#endif

