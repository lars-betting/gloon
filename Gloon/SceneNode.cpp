#include "SceneNode.h"
#include "Command.h"
#include "ForEach.h"
#include <algorithm>
#include <assert.h>
SceneNode::SceneNode()
	:mChildren()
	,mParent(nullptr)
{
}

void SceneNode::attachChild(Ptr child)
{
	child->mParent = this;
	mChildren.push_back(std::move(child));
}

SceneNode::Ptr SceneNode::detachChild(const SceneNode & node)
{
	auto found = std::find_if(mChildren.begin(), mChildren.end(), [&](Ptr& p) {return p.get() == &node; });
    _ASSERT (found != mChildren.end());

	Ptr result = std::move(*found);
	result->mParent = nullptr;
	mChildren.erase(found);
	return result;
}

void SceneNode::update(sf::Time dt)
{
	updateCurrent(dt);
	updateChildren(dt);
}


void SceneNode::updateCurrent(sf::Time dt)
{
	//Nothing by default
}

void SceneNode::updateChildren(sf::Time dt)
{
	FOREACH(Ptr& child, mChildren)
		child->update(dt);
}

void SceneNode::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	//apply tranform of current node
	states.transform *= getTransform();

	//draw node and children with changed transform
	drawCurrent(target, states);
	drawChildren(target, states);
}

void SceneNode::drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const
{
	//Do nothing by default
}

void SceneNode::drawChildren(sf::RenderTarget & target, sf::RenderStates states) const
{
	FOREACH(const Ptr& child, mChildren)
		child->draw(target, states);
}
sf::Vector2f SceneNode::getWorldPosition() const
{
	return getWorldTransform() * sf::Vector2f();
}

sf::Transform SceneNode::getWorldTransform() const
{
	sf::Transform transform = sf::Transform::Identity;

	for (const SceneNode* node = this; node != nullptr; node = node->mParent)
	{
		transform = node->getTransform() * transform;

	
	}
	return transform;
}
void SceneNode::onCommand(const Command& command, sf::Time dt)
{
	//command currenty node if category matches
	if (command.category & getCategory())
	{
		command.action(*this, dt);
	}
	FOREACH(Ptr& child, mChildren)
		child->onCommand(command, dt);
}
unsigned int SceneNode::getCategory() const
{
	return Category::Scene;
}