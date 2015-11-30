#include "Player.h"
#include "GameState.h"
#include "sfwdraw.h"
#include <vector>

//Drop player health by one if hit by an enemy
void Player::onCollision(GameObject &object, float distance)
{
	if (invinFrames <= 0)
	{
		health -= 1;
		invinFrames += 10.0f;
	}
}

void Player::update()
{
	rateOfFire -= sfw::getDeltaTime();

	//Player Movement
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
		animName = "walkLeft";
	}

	//Throw Spear based on player currentFrame for direction purposes
	if (sfw::getKey('F'))
	{
		if (animName == "walkUp")
		{
			if (rateOfFire <= 0)
			{
				gs()->throwSpear(x, y + 50, 0, speed * 1.25f, 30.f, 50);
				rateOfFire = .5f;
			}
		}
		else if (animName == "walkDown")
		{
			if (rateOfFire <= 0)
			{
				gs()->throwSpear(x, y - 50, 0, speed * -1.25, 30.f, -130);
				rateOfFire = .5f;
			}
		}
		else if (animName == "walkRight")
		{
			if (rateOfFire <= 0)
			{
				gs()->throwSpear(x + 50, y, speed * 1.25, 0, 30.f, -40);
				rateOfFire = .5f;
			}
		}
		else if (animName == "walkLeft")
		{
			if (rateOfFire <= 0)
			{
				gs()->throwSpear(x - 50, y, speed * -1.25, 0, 30.f, 140);
				rateOfFire = .5f;
			}
		}
	}
}

//Draw the player animations based on facing from Player Update
void Player::draw()
{
	animTimer +=  sfw::getDeltaTime();
	currentFrame = sampleAnimation(textureName, animName, animTimer);
	sfw::drawTexture(getTexture(textureName), x, y, width, height, 0, true, currentFrame);
}