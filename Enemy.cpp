#include "Enemy.h"
#include "Player.h"
#include "sfwdraw.h"
#include "AssetManager.h"
#include <iostream>
#include <math.h>

void Enemy::update(Player& player)
{
	float dirX = player.x - x;
	float dirY = player.y - y;
	float turnSpeed = 90;
	float movementSpeed = player.speed * .7f;
	float check;

	float goalAngle = atan2f(dirY, dirX);

	if (angle > goalAngle) { angle -= sfw::getDeltaTime() * turnSpeed; }
	else { angle += sfw::getDeltaTime() * turnSpeed; }

	velX = cos(angle) * sfw::getDeltaTime() * movementSpeed;
	velY = sin(angle) * sfw::getDeltaTime() * movementSpeed;

	x += velX;
	y += velY;
}

void Enemy::draw()
{
	sfw::drawTexture(getTexture(textureName), x, y, width, height, angle, true, 1);
}