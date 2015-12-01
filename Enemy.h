#pragma once
#include "GameObject.h"
#include "Player.h"

class Enemy : public GameObject
{
public:
	//Enemy Stats
	float velX, velY;
	float spawnRate;
	int health;

	//Base enemy Constructor
	Enemy(int spawnPoint) : velX(60), velY(60), spawnRate(2.0f), health(1)
	{
		switch (spawnPoint)
		{
		case 1:
			x = 400, y = 100;
		case 2:
			x = 400, y = 700;
		case 3:
			x = 100, y = 400;
		case 4:
			x = 700, y = 400;
		}
			width = 80, height = 80;
			isActive = true;
			animName = "slimWiggle";
			textureName = "slime";
	}

	//Enemy Functions
	void onCollision(GameObject &object, float distance);
	void update(Player& player);
	void draw();
};