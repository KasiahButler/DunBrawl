#include "Player.h"
#include "sfwdraw.h"

void Player::Movement()
{
	if (sfw::getKey('W'))
	{
		x += speed * sfw::getDeltaTime();
	}
	if (sfw::getKey('S'))
	{
		x -= speed * sfw::getDeltaTime();
	}
	if (sfw::getKey('D'))
	{
		y += speed * sfw::getDeltaTime();
	}
	if (sfw::getKey('A'))
	{
		y -= speed * sfw::getDeltaTime();
	}
}

//void Fire()
//{
//
//}

void Player::onCollision(GameObject &object, float distance)
{
	speed = 0;
	health -= 1;
}

void Player::update()
{
	Movement();
	//Fire();
}