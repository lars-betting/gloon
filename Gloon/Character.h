#pragma once

//Character class
#include <SFML\Graphics.hpp>


class Character {

public:
	Character();
	~Character();

	void draw(sf::RenderWindow* renderWindow);
	void walkRight();
	void walkLeft();
	void walkUp();
	void walkDown();
private:
	sf::CircleShape* tempShape;

};