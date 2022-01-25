#include "Mirror.h"
#include <iostream>
#include <Math.h>
Mirror::Mirror(Character& character)
{
	triangle = new sf::CircleShape(40, 3);
	triangle->setPosition(character.getPosition().x, character.getPosition().y);
	triangle->setOrigin(20.0f,80.0f);
	
	std::cout << triangle->getPosition().x << ", " << triangle->getPosition().y << std::endl;
	
}

Mirror::~Mirror()
{
}


void Mirror::moveMirror(Character & character, float deltaTime)
{
	
	triangle->rotate(0.5f);
}

void Mirror::draw(sf::RenderWindow * renderWindow)
{                 
	renderWindow->draw(*triangle);
}
