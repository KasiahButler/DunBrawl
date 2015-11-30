#pragma once
#include "GameObject.h"
#include "Player.h"

class Enemy : public GameObject
{
public:
	float velX, velY;
	float spawnRate;
	int health;

	//Base enemy Constructor
	Enemy() : velX(60), velY(60), spawnRate(2.0f), health(1)
	{
		width = 80, height = 80, x = 400, y = 100;
		isActive = true;
		animName = "slimWiggle";
		textureName = "slime";
	}

	void onCollision(GameObject &object, float distance);
	void update(Player& player);
	void draw();
};