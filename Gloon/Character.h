#pragma once

//Character class
#include <SFML\Graphics.hpp>


class Character 
{

public:
	Character();
	~Character();

	void draw(sf::RenderWindow* renderWindow);

	//Keyboard controls

	//4 DIRECTIONS
	void walkRight(float speed);
	void walkLeft(float speed);
	void walkUp(float speed);
	void walkDown(float speed);

	//8 DIRECTIONS
	void walkUpLeft(float speed);
	void walkUpRight(float speed);
	void walkDownLeft(float speed);
	void walkDownRight(float speed);

	void handleWalking(float speed);

	sf::Vector2f getPosition();
	sf::Vector2f getOrigin();
private:

	
	sf::CircleShape* tempShape;
	bool hasMirror = false;
	
};