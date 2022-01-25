#include "Character.h"
#include <iostream>

Character::Character()
{
	tempShape = new sf::CircleShape(30.f);
	tempShape->setOrigin(20.0f, 70.0f);
	tempShape->setPosition(this->getPosition());
	//std::cout << tempShape->getPosition().x << ", " << tempShape->getPosition().y << std::endl;
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
	this->move(speed, 0.0f);
}

void Character::walkLeft(float speed)
{
	this->move(-speed, 0.0f);
}

void Character::walkUp(float speed)
{
	this->move(0.0f, -speed);
}


void Character::walkDown(float speed)
{
	this->move(0.0f, speed);
}

void Character::walkUpLeft(float speed)
{
	speed = speed / sqrt(2.f);
	this->move(-speed, -speed);
}

void Character::walkUpRight(float speed)
{
	speed = speed / sqrt(2.f);
	this->move(speed, -speed);
}

void Character::walkDownLeft(float speed)
{
	speed = speed / sqrt(2.f);
	this->move(-speed, speed);
}

void Character::walkDownRight(float speed)
{
	speed = speed / sqrt(2.f);
	this->move(speed, speed);
}

void Character::handleWalking(float speed)
{
	tempShape->setPosition(this->getPosition());
//	std::cout << tempShape->getPosition().x << ", " << tempShape->getPosition().y << std::endl;
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

sf::Vector2f Character::getOrigin()
{
	sf::Vector2f origin = tempShape->getOrigin();
	return sf::Vector2f();
}

