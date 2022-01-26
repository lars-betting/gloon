#include "Player.h"
#include "CommandQueue.h"
#include "Character.h"
#include "ForEach.h"

#include <map>
#include <string>
#include <algorithm>

struct CharacterMover
{
	CharacterMover(float vx, float vy)
		: velocity(vx, vy)
	{
	}

	void operator() (Character& character, sf::Time) const
	{
		character.accelerate(velocity);
	}

	sf::Vector2f velocity;
};

Player::Player()
{
	mKeyBinding[sf::Keyboard::A] = MoveLeft;
	mKeyBinding[sf::Keyboard::D] = MoveRight;
	mKeyBinding[sf::Keyboard::W] = MoveUp;
	mKeyBinding[sf::Keyboard::S] = MoveDown;

	// set intial action bindings
	initialiseActions();

	// assing all categories to player character
	FOREACH(auto& pair, mActionBinding)
		pair.second.category = Category::Gloon;
}
void Player::handleEvent(const sf::Event& event, CommandQueue& commands)
{
	if (event.type == sf::Event::KeyPressed)
	{
		// check if pressed key appears in a key binding, if so, trigger command
		auto found = mKeyBinding.find(event.key.code);
		if (found != mKeyBinding.end() && !isRealTimeAction(found->second))
		{
			commands.push(mActionBinding[found->second]);
		}
	}
}
void Player::handleRealtimeInput(CommandQueue& commands)
{
	// Traverse all assigned keys and check if they are pressed
	FOREACH(auto pair, mKeyBinding)
	{
		// If key is pressed, lookup action and trigger corresponding command
		if (sf::Keyboard::isKeyPressed(pair.first) && isRealTimeAction(pair.second))
			commands.push(mActionBinding[pair.second]);
	}
}
void Player::assignKey(Action action, sf::Keyboard::Key key)
{
	// Remove all keys that already map to action
	for (auto itr = mKeyBinding.begin(); itr != mKeyBinding.end(); )
	{
		if (itr->second == action)
			mKeyBinding.erase(itr++);
		else
			++itr;
	}

	// Insert new binding
	mKeyBinding[key] = action;
}
sf::Keyboard::Key Player::getAssignedKey(Action action) const
{
	FOREACH(auto pair, mKeyBinding)
	{
		if (pair.second == action)
			return pair.first;
	}

	return sf::Keyboard::Unknown;
}
void Player::initialiseActions()
{
	const float playerSpeed = 200.f;

	mActionBinding[MoveLeft].action = derivedAction<Character>(CharacterMover(-playerSpeed, 0.f));
	mActionBinding[MoveRight].action = derivedAction<Character>(CharacterMover(+playerSpeed, 0.f));
	mActionBinding[MoveUp].action = derivedAction<Character>(CharacterMover(0.f, -playerSpeed));
	mActionBinding[MoveDown].action = derivedAction<Character>(CharacterMover(0.f, +playerSpeed));
}
bool Player::isRealTimeAction(Action action)
{
	switch (action)
	{
	case MoveLeft:
	case MoveRight:
	case MoveDown:
	case MoveUp:
		return true;

	default:
		return false;
	}
}