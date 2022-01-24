#include "Character.h"
#include <iostream>

Character::Character()
{
	tempShape = new sf::CircleShape(30.f);
	tempShape->setPosition(sf::Vector2f(150.f, 150.f));
	tempShape->setFillColor(sf::Color::Red);
}

Character::~Character()
{
}

void Character::draw(sf::RenderWindow* renderWindow)
{
  renderWindow->draw(*tempShape);
}

void Character::walkRight(float speed)
{
	std::cout << "walk right" << std::endl;
	tempShape->move(speed, 0.0f);
}

void Character::walkLeft(float speed)
{
	std::cout << "walk left" << std::endl;
	tempShape->move(-speed, 0.0f);
}

void Character::walkUp(float speed)
{
	std::cout << "walk up" << std::endl;
	tempShape->move(0.0f, -speed);
}


void Character::walkDown(float speed)
{
	std::cout << "walk down" << std::endl;
	tempShape->move(0.0f, speed);
}

void Character::walkUpLeft(float speed)
{
	speed = speed / sqrt(2.f);
	std::cout << "walk up left" << std::endl;
	tempShape->move(-speed, -speed);
}

void Character::walkUpRight(float speed)
{
	speed = speed / sqrt(2.f);
	std::cout << "walk up right" << std::endl;
	tempShape->move(speed, -speed);
}

void Character::walkDownLeft(float speed)
{
	speed = speed / sqrt(2.f);
	std::cout << "walk down left" << std::endl;
	tempShape->move(-speed, speed);
}

void Character::walkDownRight(float speed)
{
	speed = speed / sqrt(2.f);
	std::cout << "walk down right" << std::endl;
	tempShape->move(speed, speed);
}

void Character::handleWalking(float speed)
{
	//horizontal / vertical
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && 
		!sf::Keyboard::isKeyPressed(sf::Keyboard::W) && 
		!sf::Keyboard::isKeyPressed(sf::Keyboard::D) && 
		!sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		walkLeft(speed);
		return;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) &&
		!sf::Keyboard::isKeyPressed(sf::Keyboard::W) &&
		!sf::Keyboard::isKeyPressed(sf::Keyboard::S) &&
		!sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		walkRight(speed);
		return;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) &&
		!sf::Keyboard::isKeyPressed(sf::Keyboard::A) &&
		!sf::Keyboard::isKeyPressed(sf::Keyboard::D) &&
		!sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		walkUp(speed);
		return;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) &&
		!sf::Keyboard::isKeyPressed(sf::Keyboard::W) &&
		!sf::Keyboard::isKeyPressed(sf::Keyboard::D) &&
		!sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		walkDown(speed);
		return;
	}

	//diagonal
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::W)) 
	{
		walkUpLeft(speed);
		return;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		walkDownLeft(speed);
		return;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		walkUpRight(speed);
		return;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		walkDownRight(speed);
		return;
	}
}

sf::Vector2f Character::getPosition()
{
	sf::Vector2f position = tempShape->getPosition();
	return position;
}

