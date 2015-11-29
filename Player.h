#pragma once
#include "GameObject.h"

class Player : public GameObject
{
public:
	float speed;
	float rateOfFire;
	int health;
	char lastKey;

	Player() : speed(100), rateOfFire(0.5f), health(5)
	{
		width = 64; height = 64; x = 400; y = 400;
		textureName = "dKnight";
		animName = "walkDown";
	}

	virtual void update();
	virtual void draw();
	void onCollision(GameObject &object, float distance);
};
