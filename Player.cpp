#include "Player.h"
#include "GameState.h"
#include "sfwdraw.h"
#include <vector>

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
		currentFrame = 13;
	}
	else if (sfw::getKey('S'))
	{
		y -= speed * sfw::getDeltaTime();
		currentFrame = 1;
	}
	else if (sfw::getKey('D'))
	{
		x += speed * sfw::getDeltaTime();
		currentFrame = 9;
	}
	else if (sfw::getKey('A'))
	{
		x -= speed * sfw::getDeltaTime();
		currentFrame = 5;
	}
	if (sfw::getKey('F'))
	{
		if (currentFrame == 13)
		{
			gs()->throwSpear(x, y + 50, 0, 80, 30.f, 50);
		}
		else if (currentFrame == 1)
		{
			gs()->throwSpear(x, y - 50, 0, -80, 30.f, -130);
		}
		else if (currentFrame == 9)
		{
			gs()->throwSpear(x + 50, y, 80, 0, 30.f, -40);
		}
		else if (currentFrame = 5)
		{
			gs()->throwSpear(x - 50, y, -80, 0, 30.f, 140);
		}
	}
}

void Player::draw()
{
	/*animTimer +=  sfw::getDeltaTime();
	currentFrame = sampleAnimation(textureName, animName, animTimer);*/
	sfw::drawTexture(getTexture(textureName), x, y, width, height, 0, true, currentFrame);
	//Set base texture for standing sprite be it up/down/left/right (set bool to determine if animation is need if not then set standing sprite)
}