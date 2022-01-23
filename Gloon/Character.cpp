#include "Character.h"
#include <iostream>
Character::Character()
{
	tempShape = new sf::CircleShape(100.f);
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

void Character::walkRight()
{
	std::cout << "walk right" << std::endl;
	tempShape->move(1.0f, 0.0f);
}

void Character::walkLeft()
{
	std::cout << "walk left" << std::endl;
	tempShape->move(-1.0f, 0.0f);
}

void Character::walkUp()
{
	std::cout << "walk up" << std::endl;
	tempShape->move(0.0f, -1.0f);
}


void Character::walkDown()
{
	std::cout << "walk down" << std::endl;
	tempShape->move(0.0f, 1.0f);
}
