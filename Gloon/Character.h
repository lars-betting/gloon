#pragma once

//Character class
#include <SFML\Graphics\Sprite.hpp>
#include "Entity.h"
#include "ResourceIdentifiers.h"

class Character : public Entity
{
public:
	enum Type
	{
		Gloon
	};

public:
	Character(Type type, const TextureHolder& textures);
	virtual unsigned int getCategory() const;
private:
	virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	Type mType;
	sf::Sprite mSprite;
};