#pragma once
#include "GameObject.h"
#include "Player.h"

class Enemy : public GameObject
{
public:
	float velX, velY;
	float rateOfFire;
	int health;

	//Base enemy Constructor
	Enemy() : velX(60), velY(60), rateOfFire(2.0f), health(1)
	{
		width = 80, height = 80, x = 400, y = 100;
		animName = "slimWiggle";
		textureName = "slime";
	}

	//void onCollision(GameObject &object, float distance);
	void update(Player& player);
	void draw();
};