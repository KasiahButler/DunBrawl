#pragma once
#include "GameObject.h"

class Enemy : public GameObject
{
public:
	float speed;
	float rateOfFire;
	int health;

	Enemy() : speed(60), rateOfFire(2.0f), health(1)
	{
		width = 80, height = 80, x = 400, y = 560;
		animName = "blobSlide";
		textureName = "blob";
	}

	void movement();
	void fire();
	void onCollision(GameObject &object, float distance);
	void update();
};