#pragma once
#include "GameObject.h"

class Player : public GameObject
{
public:
	float speed;
	float rateOfFire;
	int health;

	Player() : speed(100), rateOfFire(0.5f), health(5)
	{
		width = 80; height = 80; x = 400; y = 40;
		animName = "deerRun";
		textureName = "deer";
	}

	void Movement();
	//void Fire();
	void onCollision(GameObject &object, float distance);
	void update();
};
