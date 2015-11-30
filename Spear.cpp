#include "Spear.h"

void Spear::update()
{
	duration -= sfw::getDeltaTime();
	isActive = duration > 0;

	x += velx * sfw::getDeltaTime();
	y += vely * sfw::getDeltaTime();
}

void Spear::draw()
{
	sfw::drawTexture(getTexture(textureName), x, y, 48, 48, rotation, true, 0);
}

void Spear::onCollision(GameObject& object, float distance)
{
	isActive = false;
}