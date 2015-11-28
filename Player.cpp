#include "Player.h"
#include "sfwdraw.h"

void Player::Movement()
{
	if (sfw::getKey('W'))
	{
		y += speed * sfw::getDeltaTime();
		lastKey = 'W';
	}
	if (sfw::getKey('S'))
	{
		y -= speed * sfw::getDeltaTime();
		lastKey = 'S';
	}
	if (sfw::getKey('D'))
	{
		x += speed * sfw::getDeltaTime();
		lastKey = 'D';
	}
	if (sfw::getKey('A'))
	{
		x -= speed * sfw::getDeltaTime();
		lastKey = 'A';
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

void Player::draw()
{
	if (lastKey == 'S')
	{
		sfw::drawTexture(getTexture(textureName), x, y, width, height, 0, true, 0);
	}
	else if (lastKey == 'A')
	{
		sfw::drawTexture(getTexture(textureName), x, y, width, height, 0, true, 5);
	}
	else if (lastKey == 'D')
	{
		sfw::drawTexture(getTexture(textureName), x, y, width, height, 0, true, 9);
	}
	else if (lastKey == 'W')
	{
		sfw::drawTexture(getTexture(textureName), x, y, width, height, 0, true, 13);
	}
	else sfw::drawTexture(getTexture(textureName), x, y, width, height, 0, true, 0);
}