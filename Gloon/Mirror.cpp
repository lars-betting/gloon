#include "Mirror.h"
#include <Math.h>
Mirror::Mirror(Character& character)
{
	radius = 50.f;
	milliSecondsPerOrbit = 300.0;
	theta = 0.0f;
	mirrorShape = new sf::RectangleShape(sf::Vector2f(60.f, 10.f));
	mirrorShape->setPosition(character.getPosition().x , character.getPosition().y );
}

Mirror::~Mirror()
{
}


void Mirror::moveMirror(Character & character, float deltaTime)
{
	theta += deltaTime / milliSecondsPerOrbit;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		mirrorShape->setPosition(static_cast<float>(radius*cos(theta) + character.getPosition().x), static_cast<float>(radius*sin(theta) + character.getPosition().y + 25.f));
		mirrorShape->rotate(0.045f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		mirrorShape->setPosition(static_cast<float>(radius*sin(theta) + character.getPosition().x), static_cast<float>(radius*cos(theta) + character.getPosition().y + 25.f));
	}
}

void Mirror::draw(sf::RenderWindow * renderWindow)
{                 
	renderWindow->draw(*mirrorShape);
}
