#pragma once
#include "Character.h"
class Mirror
{
public:
	Mirror(Character& character);
	~Mirror();

public:
	void moveMirror(Character& character, float deltaTime);

	void draw(sf::RenderWindow* renderWindow);
private:

	sf::RectangleShape* mirrorShape;
	
	float mirrorDistanceY;
	float mirrorDistanceX;

	float radius;
	double milliSecondsPerOrbit;
	double theta;
};

