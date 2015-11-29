#include "Enemy.h"
#include "sfwdraw.h"
#include "AssetManager.h"
#include <math.h>

void Enemy::update(GameObject& player)
{
	float dirX = player.x - x;
	float dirY = player.y - y;

	float goalAngle = atan2f(dirY, dirX);

	if (angle < goalAngle) { angle -= sfw::getDeltaTime() * speed; }
	else { angle += sfw::getDeltaTime() * speed; }

	x = cos(angle) * sfw::getDeltaTime() * speed;
	y = sin(angle) * sfw::getDeltaTime() * speed;
}

void Enemy::draw()
{
	sfw::drawTexture(getTexture("slime"), x, y, width, height, angle, true, 1);
}