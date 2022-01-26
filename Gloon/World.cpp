#include "World.h"

#include <SFML\Graphics\RenderWindow.hpp>

World::World(sf::RenderWindow& window)
	: mWindow(window)
	, mWorldView(window.getDefaultView())
	, mTextures()
	, mSceneGraph()
	, mSceneLayers()
	, mWorldBounds(0.f, 0.f, mWorldView.getSize().x, 2000.f)
	, mSpawnPosition(mWorldView.getSize().x / 2.f, mWorldBounds.height - mWorldView.getSize().y / 2.f)
	, mScrollSpeed(-50.f)
	, mPlayerCharacter(nullptr)
{
	loadTextures();
	buildScene();

	// prepare the view
	mWorldView.setCenter(mSpawnPosition);
}

void World::update(sf::Time dt)
{
	sf::Vector2f position = mPlayerCharacter->getPosition();
	sf::Vector2f velocity = mPlayerCharacter->getVelocity();

	mSceneGraph.update(dt);
}

void World::draw()
{
	mWindow.setView(mWorldView);
	mWindow.draw(mSceneGraph);
}

void World::loadTextures()
{
	mTextures.load(Textures::Gloon, "res/Textures/Gloon.png");
}

void World::buildScene()
{
	for (std::size_t i = 0; i < LayerCount; i++)
	{
		SceneNode::Ptr layer(new SceneNode());
		mSceneLayers[i] = layer.get();

		mSceneGraph.attachChild(std::move(layer));
	}

	//Prepare the tiled background
	sf::Texture& texture = mTextures.get(Textures::TempBackground);
	sf::IntRect textureRect(mWorldBounds);
	texture.setRepeated(true);

	std::unique_ptr<SpriteNode> backgroundSprite(new SpriteNode(texture, textureRect));
	backgroundSprite->setPosition(mWorldBounds.left, mWorldBounds.top);
	mSceneLayers[Air]->attachChild(std::move(backgroundSprite));

	std::unique_ptr<Character> gloon(new Character(Character::Gloon, mTextures));
	mPlayerCharacter = gloon.get();
	mPlayerCharacter->setPosition(mSpawnPosition);
	mPlayerCharacter->setVelocity(40.f, mScrollSpeed);
	mSceneLayers[Air]->attachChild(std::move(gloon));
	
}