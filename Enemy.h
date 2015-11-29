#pragma once
#include "GameObject.h"

class Enemy : public GameObject
{
public:
	float speed;
	float rateOfFire;
	int health;

	//Base enemy Constructor
	Enemy() : speed(60), rateOfFire(2.0f), health(1)
	{
		width = 80, height = 80, x = 400, y = 100;
		animName = "blobSlide";
		textureName = "blob";
	}

	//void onCollision(GameObject &object, float distance);
	void update(GameObject& player);
	void draw();
};