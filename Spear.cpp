#include "Spear.h"

//Keeps track of Spear duration and updates position
void Spear::update()
{
	duration -= sfw::getDeltaTime();
	isActive = duration > 0;

	x += velx * sfw::getDeltaTime();
	y += vely * sfw::getDeltaTime();
}

//Render Spear to Game Window
void Spear::draw()
{
	sfw::drawTexture(getTexture(textureName), x, y, 48, 48, rotation, true, 0);
}

//Deletes Spear when it collides (Usually with an enemy)
void Spear::onCollision(GameObject& object, float distance)
{
	isActive = false;
}