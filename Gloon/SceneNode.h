#pragma once

#include "Category.h"

#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Drawable.hpp>

#include <SFML/System/NonCopyable.hpp>
#include <SFML/System/Time.hpp>

#include <vector>
#include <memory>
//abstract base node class

struct Command;
class SceneNode : public sf::Transformable, public sf::Drawable, private sf::NonCopyable
{

public:
	typedef std::unique_ptr<SceneNode> Ptr;

public:
	SceneNode();
	
	void attachChild(Ptr child);
	Ptr detachChild(const SceneNode& node);

	void update(sf::Time dt);

	sf::Vector2f getWorldPosition() const;
	sf::Transform getWorldTransform() const;

	void onCommand(const Command& command, sf::Time dt);
	virtual unsigned int getCategory() const;

private:
	virtual void updateCurrent(sf::Time dt);
	void updateChildren(sf::Time dt);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
	void drawChildren(sf::RenderTarget& target, sf::RenderStates states) const;
	
private:
	std::vector<Ptr> mChildren;
	SceneNode* mParent;
};

