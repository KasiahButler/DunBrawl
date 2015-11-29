#include "Player.h"
#include "sfwdraw.h"

void Player::onCollision(GameObject &object, float distance)
{
	speed = 0;
	health -= 1;
}

void Player::update()
{
	if (sfw::getKey('W'))
	{
		y += speed * sfw::getDeltaTime();
		animName = "walkUp";
	}
	if (sfw::getKey('S'))
	{
		y -= speed * sfw::getDeltaTime();
		animName = "walkDown";
	}
	if (sfw::getKey('D'))
	{
		x += speed * sfw::getDeltaTime();
		animName = "walkRight";
	}
	if (sfw::getKey('A'))
	{
		x -= speed * sfw::getDeltaTime();
		animName = "walkRight";
	}
	if (sfw::getKey(KEY_ENTER))
	{
		//gs->throwJavelin(); Need to implement projectile function and set array of projectiles
	}
}

void Player::draw()
{
	//set the animation loop here based on if player is walking and what direction (movement in update will set animName to the correct animation so I don't need to manually do it each time)
	//Set base texture for standing sprite be it up/down/left/right (set bool to determine if animation is need if not then set standing sprite)
}