#include "Character.h"
#include "ResourceHolder.h"

#include <SFML\Graphics\RenderTarget.hpp>
#include <SFML\Graphics\RenderStates.hpp>

Textures::ID toTextureID(Character::Type type)
{
	switch (type)
	{
	case Character::Gloon:
		return Textures::Gloon;
	}
	return Textures::Gloon;
}
Character::Character(Type type, const TextureHolder& textures)
	: mType(type)
	, mSprite(textures.get(toTextureID(type)))
{
	sf::FloatRect bounds = mSprite.getLocalBounds();
	mSprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}

void Character::drawCurrent(sf::RenderTarget& target, sf::RenderStates states)const
{
	target.draw(mSprite, states);
}

unsigned int Character::getCategory() const
{
	switch (mType)
	{
	case Gloon:
		return Category::Gloon;
	}
}
